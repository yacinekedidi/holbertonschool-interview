#!/usr/bin/python3
"""
lockboxes function
"""


def canUnlockAll(boxes):
    """
    determines if all the boxes can be opened.
    """
    if len(boxes) <= 1:
        return True
    keys = [0]
    looped = []
    while len(keys):
        for i in boxes[keys[0]]:
            if i not in keys and i not in looped and i < len(boxes):
                keys.append(i)
        looped.append(keys.pop(0))
        if len(looped) == len(boxes):
            return True
    return False
