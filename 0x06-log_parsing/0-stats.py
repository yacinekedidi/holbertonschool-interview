#!/usr/bin/python3
"""Module



"""
import sys
argv = sys.argv


def printStatus(status, sum):
    """
    print the stats and size.
    """
    try:
        print('File size: {}'.format(sum))
        [print("{}: {}".format(k, v))
         for k, v in sorted(status.items()) if v != 0]
    except Exception:
        pass


status = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0,
}
sum = 0
list = []
try:
    for i, line in enumerate(sys.stdin, 1):
        list = line.split(' ')

        if len(list[-2]):
            if (list[-2].isdigit()):
                try:
                    status[list[-2]] += 1
                except Exception:
                    pass
        try:
            sum += int(list[-1].replace('\n', ''))
        except Exception:
            pass
        if i % 10 == 0:
            printStatus(status, sum)
except KeyboardInterrupt:
    printStatus(status, sum)
    raise
