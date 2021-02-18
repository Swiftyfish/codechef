# -*- coding: utf-8 -*-
"""
Created on Sat Jan  9 00:01:10 2021

@author: swift
"""

import numpy as np

arr1 = [1, 5, 3, 6, 7]
arr2 = [1, 3, 2, 4, 7]

arr2 = list(set(arr2))
#Can choose an index i from arr1 and j from arr2 and perform arr1[i] = arr2[j]
#i.e. set an element of arr1 equal to one from arr2
#return number of operations to make arrr1 strictly increasing or return -1 if not possible

#sort arr2 so we can find values more easily
#need to be able to identify areas of arr1 which are not strictly increasing
#can do this by comparing them with their neighbours

#want to be able to find groups of 'bad' values so that we can first check whether it is possible to assign each of these 
#values a new value in between the bordering values

#or update the bordering values to allow for a greater range over the 'bad' values

#can look at each slot to see which values it can be exchanged with.
#if a bad values neighbours are 'fixed' and it cannot take a value in their range then return -1
#i.e. 1,5,3 with arr2 = 1,6,3,3
#5 is a bad value but none of the values in arr2 resolve the array.

#if arr2 can be transformed into a set with length greater than arr1 then the array is rearrangable.

#dp state is the index in arr1 and the previous index in the sorted and reduced arr2

dp = np.zeros((len(arr1), len(arr2)), int)
dp.fill(100)
dp[0][0] = 0

for ii in range(len(arr1)):
    for jj in range(len(arr2)):
        if ii < len(arr1):
            if arr2[jj] > arr1[ii + 1]:
                dp[ii][jj] = dp[ii + 1][jj + 1]