from collections import defaultdict
from functools import cmp_to_key

def sort_function(a, b):
    if a[0] != b[0]:
        if a[0] < b[0]:
            return 1
        elif a[0] > b[0]:
            return -1
        else:
            return 0
    else:
        if a[1] < b[1]:
            return -1
        elif a[1] > b[1]:
            return 1
        else:
            return 0

m = int(input())
d = defaultdict(lambda : defaultdict(int))
used_words = set()

# fill up the dict
for _ in range(m):
    tokens = input().split()
    user, words = tokens[0], tokens[1:]
    for word in words:
        d[user][word] += 1
        used_words.add(word)

# get all the words used by every single user
global_words = []
for word in used_words:
    is_global = True
    for key, val in d.items():
        if word not in val:
            is_global = False
            break
    if is_global:
        global_words.append(word)

if len(global_words) == 0:
    print("ALL CLEAR")
else:
    # order words from most used to least
    lst = []
    for word in global_words:
        count = 0
        for val in d.values():
            count += val[word]
        lst.append((count, word))
    lst.sort(key=cmp_to_key(sort_function))
    for pair in lst:
        print(pair[1])



