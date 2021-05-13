#!/usr/bin/python3
"""
function
"""


def minOperations(n):
    """
    calculates the fewest number of operations
    """
    if n <= 1:
        return 0
    currentCharacters = 2
    copiedCharacters = 1
    actions = {
        'copyAll': 1,
        'paste': 1
    }
    while (currentCharacters < n):
        diff = n - currentCharacters
        if n % currentCharacters == 0 and copiedCharacters <= diff:
            actions['copyAll'] += 1
            copiedCharacters = currentCharacters
        actions['paste'] += 1
        currentCharacters += copiedCharacters
    return sum(actions.values())
