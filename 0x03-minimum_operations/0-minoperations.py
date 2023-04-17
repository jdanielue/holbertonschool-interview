#!/usr/bin/python3

""" Minimum Ope """


def minOperations(n):
    """
    In a text file, there is a single character H. 
    Returns an integer
    If n is impossible to achieve, returns 0
    """
    if not isinstance(n, int):
        return 0

    op = 0
    i = 2
    while (i <= n):
        if not (n % i):
            n = int(n / i)
            op += i
            i = 1
        i += 1
    return op