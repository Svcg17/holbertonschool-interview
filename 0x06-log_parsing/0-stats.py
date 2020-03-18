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
statCount = {}


def handleTen(statCount, fileSize):
    sys.stdout.write("File size: {}\n".format(fileSize))
    for key in sorted(statCount.keys()):
        sys.stdout.write("{}: {}\n".format(key, statCount[key]))


try:
    for line in sys.stdin:
        split = line.split(" ")
        status = split[7]
        fileSize += int(split[8])

        if statCount.get(status):
            statCount[status] += 1
        else:
            statCount[status] = 1

        if c == 9:
            handleTen(statCount, fileSize)
            c = fileSize = 0

        c += 1
    else:
        handleTen(statCount, fileSize)


except KeyboardInterrupt:
    handleTen(statCount, fileSize)
