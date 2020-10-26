"""
Please write you name here: Joshua Swift
"""
from datetime import datetime as dt
import pandas as pd
import numpy as np
import re

def coerce_times(timestamps):
    """

    Need to process some times differently since pandas cannot infer their format automatically.
    """
    out = []
    for time in timestamps:
        afternoon = ['PM' in val for val in time.split('-')]
        #Strip AM and PM tags from strings as well as white space
        left, right = [x.strip().replace('PM', '').replace('AM', '') \
             for x in time.split('-')]
        left_hour = int(re.match(r"([0-9]+)[.:]*", left).group(1))
        left_min = re.search(r"[.:]([0-9]{2})", left)
        left_min = int(left_min.group(1))/60 if left_min else 0

        right_hour = int(re.match(r"([0-9]+)[.:]*", right).group(1))
        right_min = re.search(r"[.:]([0-9]{2})", right)
        right_min = int(right_min.group(1))/60 if right_min else 0
        left_out = left_hour + left_min
        right_out = right_hour + right_min #output will be decimal 18:30 -> 18.5

        if any(afternoon):
            #if one of the times had a PM tag we need to add 12 hours to both
            #could potentially check for overflow for larger scale application
            #but can currently trust that data is correctly formatted
            #i.e. no instances of 17PM which could overflow to the next day
            left_out += 12; right_out += 12
        out.append((left_out, right_out))
    return out

def process_shifts(path_to_csv):
    """

    :param path_to_csv: The path to the work_shift.csv
    :type string:
    :return: A dictionary with time as key (string) with format %H:%M
        (e.g. "18:00") and cost as value (Number)
    For example, it should be something like :
    {
        "17:00": 50,
        "22:00: 40,
    }
    In other words, for the hour beginning at 17:00, labour cost was
    50 pounds
    :rtype dict:
    """
    costs = {}
    times = {}
    for i in range(0, 24):
        time = (len(str(i)) == 1)*'0' + str(i) + ':00'
        costs[time] = 0
        times[i] = time

    data = pd.read_csv(path_to_csv)
    data.sort_values(['start_time', 'end_time'])
    breaks = data.break_notes.values
    times = coerce_times(breaks) #get processed times
    data["breaks_start"], data["breaks_end"] = zip(*times)
    data.drop("break_notes", 1, inplace=True)
    data["start_time"] = pd.to_datetime(data.start_time)
    data["end_time"] = pd.to_datetime(data.end_time)

    for entry in data.values:
        work = [0 for i in range(0, 24)]
        start = entry[2].hour + entry[2].minute/60
        end = entry[0].hour + entry[0].minute/60
        break_start, break_end = entry[3], entry[4]
        pay = entry[1]
        if break_start < start:
            break_start += 12
            break_end += 12
        for i in range(0, 24):
            if start <= i < break_start or break_end <= i < end:
                work[i] = 1
        if int(break_end) < break_end:
            work[int(break_end)] = abs(int(break_end) - break_end)
        if int(break_start) < break_start:
            work[int(break_start)] = abs(int(break_start) - break_start)
        diff = start - int(start)
        if (diff > 0):
            work[int(start)] = diff
        diff = end - int(end)
        if (diff > 0):
            work[int(end)] = diff
        for i in range(0, 24):
            time = (len(str(i)) == 1)*'0' + str(i) + ':00'
            costs[time] += round(work[i] * pay, 2)

    return costs


def process_sales(path_to_csv):
    """

    :param path_to_csv: The path to the transactions.csv
    :type string:
    :return: A dictionary with time (string) with format %H:%M as key and
    sales as value (string),
    and corresponding value with format %H:%M (e.g. "18:00"),
    and type float)
    For example, it should be something like :
    {
        "17:00": 250,
        "22:00": 0,
    },
    This means, for the hour beginning at 17:00, the sales were 250 dollars
    and for the hour beginning at 22:00, the sales were 0.

    :rtype dict:
    """
    data = pd.read_csv(path_to_csv)
    data.time = pd.to_datetime(data.time)
    data.time = pd.DatetimeIndex(data.time).strftime('%H:00')
    out = data.groupby('time').sum().round(2).to_dict()['amount']
    return out

def compute_percentage(shifts, sales):
    """

    :param shifts:
    :type shifts: dict
    :param sales:
    :type sales: dict
    :return: A dictionary with time as key (string) with format %H:%M and
    percentage of labour cost per sales as value (float),
    If the sales are null, then return -cost instead of percentage
    For example, it should be something like :
    {
        "17:00": 20,
        "22:00": -40,
    }
    :rtype: dict
    """
    out = {}
    for key in list(shifts.keys()):
        if key in list(sales.keys()):
            out[key] = round(shifts[key]/sales[key] * 100, 2)
        else:
            out[key] =  0 if shifts[key] == 0 else -shifts[key]

    return out

def best_and_worst_hour(percentages):
    """

    Args:
    percentages: output of compute_percentage
    Return: list of strings, the first element should be the best hour,
    the second (and last) element should be the worst hour. Hour are
    represented by string with format %H:%M
    e.g. ["18:00", "20:00"]

    """

    #Question was a little unclear as to whether no sales with labour cost (negative value)
    #is worse than high percentage labour cost.
    #I chose to return the highest percentage as the worst hour
    
    #can just sort the pairs from the dictionary since there are only 24 of them
    pairs = list(percentages.items())
    pairs.sort(key=lambda x: x[1])
    minmax = [pairs[0][0], pairs[-1][0]]
    for pair in pairs:
        if pair[1] > 0:
            minmax[0] = pair[0]
            break

    return minmax

def main(path_to_shifts, path_to_sales):
    """
    Do not touch this function, but you can look at it, to have an idea of
    how your data should interact with each other
    """

    shifts_processed = process_shifts(path_to_shifts)
    sales_processed = process_sales(path_to_sales)
    percentages = compute_percentage(shifts_processed, sales_processed)
    best_hour, worst_hour = best_and_worst_hour(percentages)
    return best_hour, worst_hour

if __name__ == '__main__':
    # You can change this to test your code, it will not be used
    path_to_sales = "transactions.csv"
    path_to_shifts = "work_shifts.csv"
    best_hour, worst_hour = main(path_to_shifts, path_to_sales)


# Please write you name here: Joshua Swift
