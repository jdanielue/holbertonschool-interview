#!/usr/bin/python3
""" Rotate 2d matrix 90 degrees """


def rotate_2d_matrix(matrix):
    """ Rotate 2d matrix 90 degrees """

    n = len(matrix)

    for r in range(n):
        for c in range(r, n):
            matrix[r][c], matrix[c][r] = matrix[c][r], matrix[r][c]

    for i in range(n):
        matrix[i].reverse()
