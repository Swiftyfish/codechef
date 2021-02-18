# -*- coding: utf-8 -*-
"""
Created on Sun Jan 10 17:47:13 2021

@author: swift
"""
#s2 = "00110011"
#s2 = "00100100"
s2 = "10101"

def countBinarySubstrings(s):
        #need the number of the first digit and a way to tell when the digits swap
        #such that 0010 is flagged as invalid and dropped
        
        # need to be able to:
        #   drop an given element when it becomes invalid or is a complete substring
        #   mark how many of a digit is in the first half of the substring
        #   mark how many of the second digit are needed to be a complete substring
        count = 0
        substrings = []
                
        for char in s:
            digit = char == '1'
            for ii in range(len(substrings)):
                z, o, first = substrings[ii]
                if digit:
                    if (o and not z) or not first:
                        o += 1
                    else:
                        o = z = 0
                    
                else:
                    if (z and not o) or first:
                        z += 1
                    else: 
                        o = z = 0
                pass       
                substrings[ii] = (z, o, first)
                
                if o == z > 0:
                    count += 1
                    
            substrings = [(z, o, check) for z, o, check in substrings if z != o] # remove resolved substrings
            
            substrings.append((not digit, digit, digit))
            
        return count
    
def countBinarySubstrings2(s):
        #need the number of the first digit and a way to tell when the digits swap
        #such that 0010 is flagged as invalid and dropped
        
        # need to be able to:
        #   drop an given element when it becomes invalid or is a complete substring
        #   mark how many of a digit is in the first half of the substring
        #   mark how many of the second digit are needed to be a complete substring
        count = 0
        reps = 0
        inputs = []
        last = int(s[0] == "1")
        for char in s2:
            digit = int(char == "1")
            if digit == last:
                reps += 1
            else:
                inputs.append(reps)
                reps = 1
                last = digit
        if last == digit:
            inputs.append(reps)
        
                
        for ii in range(len(inputs)):
            if ii > 0:
                count += min(inputs[ii - 1], inputs[ii])
            
        return count
    
countBinarySubstrings2(s)
