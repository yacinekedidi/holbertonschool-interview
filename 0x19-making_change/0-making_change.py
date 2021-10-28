#!/usr/bin/python3
"""Module"""


def makeChange(coins, total):
    """
     determine the fewest number of coins needed to meet a given amount total
    """
    if total <= 0:
        return 0
    if not coins or len(coins) == 0:
        return -1

    if total in coins:
        return 1

    number_of_coins = 0
    filter_coins = list(filter(lambda x: True if x <= total else False, coins))
    filter_coins.sort(reverse=True)

    for i in filter_coins:
        rest = total // i
        total -= (rest * i)
        number_of_coins += rest
        if total == 0:
            return number_of_coins
        while total < filter_coins[-1]:
            total += i
            number_of_coins -= 1
    return -1
