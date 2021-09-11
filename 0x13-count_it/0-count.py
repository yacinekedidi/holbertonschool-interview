#!/usr/bin/python3
import requests


def count_words(subreddit, word_list, word_count={}, after=''):
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'user-agent': 'yacinekedidi'}
    params = {'after': after}
    response = requests.get(url, headers=headers, params=params)
    if response.status_code != 200:
        return
    r = response.json()
    data = r.get('data')
    after = r.get("after")
    articles = data.get("children")
    for article in articles:
        for word in word_list:
            word = word.lower()
            if not word_count.get(word):
                word_count[word] = 0
            word_count[word] += \
                article.get("data").get("title").lower().count(word)

    if not after:
        if not sum(word_count.values()):
            return

        words = [w for w in sorted(word_count.values())]
        words = words[::-1]
        d = {}
        for w in words:
            for k, v in word_count.items():
                if v == w:
                    d[k] = v
        [print("{}: {}".format(keyword, how_many))
            for keyword, how_many in d.items()]
    else:
        count_words(subreddit, word_list, word_count, after)
