#!/usr/bin/python3
def validUTF8(data):
    counter = 0
    for num in data:
        mask = 0b10000000
        if not counter:
            while (mask & num):
                counter += 1
                mask >>= 1
            if counter > 4:
                return False
            if counter:
                counter -= 1
                if counter == 0:
                    return False
        elif counter:
            if num >> 6 == 2:
                counter -= 1
            else:
                return False
    if not counter:
        return True
    else:
        return False
