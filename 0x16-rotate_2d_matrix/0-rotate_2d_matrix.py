#!/usr/bin/python3
"""Rotate 2D Matrix"""


def swap(matrix, i, j):
    """Swaps the values of an matrix
    """
    matrix[i][j] = matrix[i][j] * matrix[j][i]
    matrix[j][i] = matrix[i][j] // matrix[j][i]
    matrix[i][j] = matrix[i][j] // matrix[j][i]


def rotate_2d_matrix(matrix):
    """Rotates a matrix in place 90 degrees
    Args:
        matrix: 2d list of integers to rotate
    """
    for i in range(len(matrix)):
        for j in range(i + 1, len(matrix[i])):
            swap(matrix, i, j)

    for i in range(len(matrix)):
        matrix[i][0] = matrix[i][0] * matrix[i][2]
        matrix[i][2] = matrix[i][0] // matrix[i][2]
        matrix[i][0] = matrix[i][0] // matrix[i][2]
