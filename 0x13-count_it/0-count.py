#!/usr/bin/python3
"""Module"""
import requests


def count_words(subreddit, word_list, word_count={}, after=''):
    """[summary]

    Args:
        subreddit ([type]): [description]
        word_list ([type]): [description]
        word_count (dict, optional): [description]. Defaults to {}.
        after (str, optional): [description]. Defaults to ''.
    """
    url = "https://www.reddit.com/r/{}/hot.json?limit=100".format(subreddit)
    headers = {'user-agent': 'yacinekedidi'}
    params = {'after': after}
    response = requests.get(url, headers=headers, params=params)
    if response.status_code != 200 or not len(word_list):
        return
    r = response.json()
    data = r.get('data')
    after = r.get("after")
    articles = data.get("children")
    for article in articles:
        for word in word_list:
            word = word.lower()
            how_many = article.get("data").get("title").lower().count(word)
            if not word_count.get(word):
                word_count[word] = how_many
            else:
                word_count[word] += how_many

    if not after:
        if not sum(word_count.values()):
            return

        words = [w for w in sorted(word_count.values())]
        words = words[::-1]
        d = {}
        for w in words:
            for k, v in word_count.items():
                if v == w and v != 0:
                    d[k] = v
        [print("{}: {}".format(keyword, how_many))
            for keyword, how_many in d.items()]
    else:
        count_words(subreddit, word_list, word_count, after)
