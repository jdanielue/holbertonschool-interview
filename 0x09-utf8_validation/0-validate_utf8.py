#!/usr/bin/python3
"""
UTF-8 encoding
"""


def validUTF8(data):
    """
    Return: True if data is a valid
    """
    try:
        bytes(number & 0xFF for number in data).decode()
        return True
    except UnicodeDecodeError:
        return False