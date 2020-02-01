#!/usr/bin/python3
"""
    Determine wether all boxes can be unlocked by other boxes' values
    @boxes: 2d array of boxes with values inside them
    Returns: True or False
"""


def canUnlockAll(boxes):
    newList = [0]
    i = j = 0
    for i in newList:
        for j in boxes[i]:
            if j not in newList:
                newList.append(j)
            else:
                continue
    if len(newList) == len(boxes):
        return True
    else:
        return False
