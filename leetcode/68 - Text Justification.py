# -*- coding: utf-8 -*-
"""
Created on Thu Jan  7 19:31:03 2021

@author: swift
"""

#words = ["This", "is", "an", "example", "of", "text", "justification."]
#words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16

def fullJustify(words, maxWidth):
    line = []
    answer = []
    lineLength = 0

    for word in words:
        if lineLength + len(word) + (lineLength != 0) <= maxWidth:
            line += [word]
            lineLength += len(word) + (lineLength != 0)
        else:
            if len(line) == 1:
                answer += [line[0] + " " * (maxWidth - len(line[0]))]
                line = [word]
                lineLength = len(word)
                continue
        
            #Calculate number of spaces needed
            spaces = maxWidth - lineLength + len(line) - 1
            spacesPer = spaces // (len(line) - 1)
            spacesExtra = spaces % (len(line) - 1)
        
            #Pad starting from the left with trailing spaces
            for i in range(spacesExtra):
                line[i] += ' '
            
            answer += [(" " * spacesPer).join(line)]
            line = [word]
            lineLength = len(word)
        
    last = " ".join(line)
    last += " " * (maxWidth - len(last))
    answer += [last]
    
    return answer
    
answer = fullJustify(words, maxWidth)
