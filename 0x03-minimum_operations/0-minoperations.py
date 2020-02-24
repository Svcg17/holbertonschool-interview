#!/usr/bin/python3
"""
    calculates the fewest number of operations needed to result in exactly n H characters.
    Args:
        @n: integer
    Return: the fewest number of operations needed to result in exactly n H characters
"""
def minOperations(n):
    suma = 0
    if n <= 1:
        return suma
    elif n % 2 != 0:
        return n
    else:
        for i in range(2, n + 1):
            while n % i == 0:
                suma += i
                n = n // i
    return suma
            