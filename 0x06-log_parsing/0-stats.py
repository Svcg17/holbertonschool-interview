#!/usr/bin/python3
"""
    Reads stdin line by line and computes metrics:
    For every 10 lines:
        - print the status number with the number of times it
        appears
        - print the sum of the file sizes
"""
import sys
import signal

c = fileSize = 0
statCount = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
             "404": 0, "405": 0, "500": 0}


def handleTen(statCount, fileSize):
    print("File size: {}".format(fileSize))
    for key in sorted(statCount.keys()):
        if statCount[key] == 0:
            continue
        print("{}: {}".format(key, statCount[key]))


try:
    for line in sys.stdin:
        split = line.split(" ")
        status = split[7]
        fileSize += int(split[8])

        if status in statCount:
            statCount[status] += 1

        if c == 9:
            handleTen(statCount, fileSize)
            c = fileSize = 0

        c += 1
    else:
        handleTen(statCount, fileSize)


except (KeyboardInterrupt, SystemExit):
    handleTen(statCount, fileSize)
    raise
