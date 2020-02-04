#!/usr/bin/python3
"""
    Determine wether all boxes can be unlocked by other boxes' values
    @boxes: 2d array of boxes with values inside them
    Returns: True or False
"""


def canUnlockAll(boxes):
    newList = [0]
    i = j = 0
    if not boxes or not isinstance(boxes, list):
        return False
    if len(boxes) == 0:
        return True

    for i in newList:
        for j in boxes[i]:
            if not isinstance(j, int) or j < 0 or j > len(boxes):
                return False
            if j not in newList:
                newList.append(j)
            else:
                continue
    if len(newList) == len(boxes):
        return True
    else:
        return False
