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

    def is_smaller(num):
        if num <= total:
            return True
        else:
            return False

    filtered_coins = list(filter(is_smaller, coins))
    filtered_coins.sort(reverse=True)

    for i in filtered_coins:
        rest = total / i
        total -= (rest * i)
        number_of_coins += rest
        if total == 0:
            return number_of_coins
    if total != 0:
        return -1

