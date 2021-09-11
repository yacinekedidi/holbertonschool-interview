
#!/usr/bin/python3
"""Module"""
import requests


def count_words(subreddit='', word_list=[], word_count={}, after=''):
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

    word_list = list(set([w.lower() for idx, w in enumerate(word_list)]))
    r = response.json()
    data = r.get('data', {})
    after = data.get("after", '')
    articles = data.get("children", [])
    for article in articles:
        title = article.get("data", {}).get("title", '').lower()
        for word in word_list:
            how_many = title.count(word)
            if not word_count.get(word):
                word_count[word] = how_many
            elif how_many:
                word_count[word] += how_many

    if not after:
        if not len(word_count.keys()):
            return

        words = [w for w in sorted(word_count.values())]
        words = words[::-1]
        d = {}
        for w in words:
            for k, v in word_count.items():
                if v == w and v != 0:
                    d[k] = v
        word_count = d
        [print("{}: {}".format(keyword, how_many))
            for keyword, how_many in word_count.items()]
    else:
        count_words(subreddit, word_list, word_count, after)
