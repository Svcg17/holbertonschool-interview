#!/usr/bin/python3
"""
    Reads stdin line by line and computes metrics:
    For every 10 lines:
        - print the status number with the number of times it
        appears
        - print the sum of the file sizes
"""
import sys

c = fileSize = 0
statCount = {}

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
    if c == 9:
        for key in sorted(statCount.keys()):
            sys.stdout.write("{}: {}\n".format(key, statCount[key]))
        sys.stdout.write("File size: {}\n".format(fileSize))
        c = fileSize = 0
        statCount = {}
