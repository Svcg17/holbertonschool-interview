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


def handleTen(statCount, c, fileSize):
    for key in sorted(statCount.keys()):
        sys.stdout.write("{}: {}\n".format(key, statCount[key]))
    sys.stdout.write("File size: {}\n".format(fileSize))
    c = fileSize = 0
    statCount = {}
    return statCount, c, fileSize


try:
    for line in sys.stdin:
        split = line.split(" ")
        if len(split) < 9:
            continue
        status = split[7]
        fileSize += int(split[8])

        if statCount.get(status):
            statCount[status] += 1
        else:
            statCount[status] = 1

        c += 1
        if c == 10:
            statCount, c, fileSize = handleTen(statCount, c, fileSize)
    else:
        statCount, c, fileSize = handleTen(statCount, c, fileSize)


except KeyboardInterrupt:
    statCount, c, fileSize = handleTen(statCount, c, fileSize)
