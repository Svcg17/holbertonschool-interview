#!/usr/bin/python3
"""
    calculates the fewest number of operations needed to result in
    exactly n H characters.
    Args:
        @n: integer
    Return: the fewest number of operations needed to result in n H characters
"""


def minOperations(n):
    suma = 0
    if n <= 1:
        return suma
    for i in range(2, n):
        while n % i == 0:
            suma += i
            n = n // i
    if n > 1:
        suma += n
    return suma
