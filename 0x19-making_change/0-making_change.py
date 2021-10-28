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

    number_of_coins = 1

    def is_smaller(num):
        if num <= total:
            return True
        else:
            return False

    filtered_coins = list(filter(is_smaller, coins))
    filtered_coins.sort(reverse=True)

    x = filtered_coins[0]
    for idx, i in enumerate(filtered_coins):
        while total - x >= i:
            x += i
            number_of_coins += 1
            if x == total:
                return number_of_coins
        """if idx + 1 < len(filtered_coins):
            while total - x < filtered_coins[idx + 1]:
                x -= i
                number_of_coins -= 1
        """
    return -1
