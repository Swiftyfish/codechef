# -*- coding: utf-8 -*-
"""
Created on Tue Nov 10 19:20:06 2020

@author: swift
"""

import numpy as np
from tqdm import tqdm

def run_simulation(probs, reqs=None):
    if reqs is None:
        reqs = [1 for i in probs]
        
    num = 1
    for i in range(1, len(probs)):
        num = np.lcm(num, probs[i])
        
    vals = [num//i for i in probs] #how many rolls each drop needs
    check = [0, 0, 0, 0]
    kills = 0
    while not all(check[i] >= reqs[i] for i in range(len(reqs))):
        kills += 1
        roll = np.random.randint(num)
        if roll > sum(vals):
            continue
        for i in range(len(vals)):
            roll -= vals[i]
            if roll < 0:
                check[i] += 1
                break
                
    return kills, check

kills = []
for i in tqdm(range(1000)):
    k, s = run_simulation([281, 281])
    kills.append(k)
np.mean(kills)
                    

            
        
        
        

