#!/usr/bin/python
# -*- coding: utf-8 -*-

"""_module_
"""


def is_prime(num):
    """checks if its a prime number
    
    Keyword arguments:
    @num -- number to check
    Return: return True if number is prime otherwise False
    """

    for dividor in range(2, int(num ** 0.5) + 1):
        if num % dividor == 0:
            return False
    return True


def primes_count(n):
    """counts prime numbers in a given range
    
    Keyword arguments:
    @n -- range number
    Return: return the count of prime numbers in range n
    """

    primes = 0
    for num in range(2, n + 1):
        if is_prime(num):
            primes += 1
    return primes


def isWinner(x, nums):
    """
    Maria and Ben are playing a game.
    Given a set of consecutive integers starting from 1 up to and including n,
    they take turns choosing a prime number from the set
    and removing that number and its multiples from the set.
    The player that cannot make a move loses the game.
    They play x rounds of the game, where n may be different for each round.
    Assuming Maria always goes first and both players play optimally, 
    determine who the winner of each game is.

    
    Keyword arguments:
    @x -- the number of rounds they play
    @nums -- an array of n
    Return: a string Ben if he wins otherwise string Maria or
            None if undetermined
    """

    if x < 1 or x != len(nums):
        return None
    maria_wins = 0
    ben_wins = 0

    for round in range(x):
        if primes_count(nums[round]) % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1
    if ben_wins == maria_wins:
        return None
    return ('Ben' if ben_wins > maria_wins else 'Maria')
