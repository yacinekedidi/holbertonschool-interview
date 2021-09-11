#!/usr/bin/python3
"""function"""
import requests


def count_words(subreddit, word_list, words_count={}, after=""):
    """
    queries the Reddit API, parses the title of all hot articles,
    prints a sorted count of given keywords
    """
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'user-agent': 'yacinekedidi'}
    params = {'after': after}
    response = requests.get(url, headers=headers, params=params)
    if response.status_code != 200:
        print()
        return
    r = response.json()
    infos = r.get("data")
    after = infos.get("after")
    for c in infos.get("children"):
        title = c.get("data").get("title").lower().split()
        for w in word_list:
            if w.lower() in title:
                how_many = len([t for t in title if t == w.lower()])
                if words_count.get(w) is None:
                    words_count[w] = how_many
                else:
                    words_count[w] += how_many

    if not after:
        if len(words_count) == 0:
            print()
            return
        words = [w for w in sorted(words_count.values())]
        words = words[::-1]
        d = {}
        for i in words_count.keys():
            for j in words:
                if words_count[i] == j:
                    d[i] = j
        words_count = d
        [print("{}: {}".format(k, v)) for k, v in words_count.items()]
    else:
        count_words(subreddit, word_list, words_count, after)
