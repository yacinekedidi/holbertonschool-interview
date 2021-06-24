#!/usr/bin/python3
"""
Module
"""


def validUTF8(data):
    """
    determines if a given data set represents a valid UTF-8 encoding.
    """
    ones = 0
    binaryList = ['{:0>8}'.format(str(bin(n))[2:]) for n in data]
    if binaryList[0][0] == '0':
        return True
    else:
        for i in binaryList[0]:
            if i == '1':
                ones += 1
            else:
                break
        if binaryList[0][ones+1] != 0:
            return False
        for i in binaryList[1:]:
            if i[0] != '1' or i[1] != '0':
                return False
    return True
