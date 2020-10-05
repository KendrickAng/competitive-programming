import sys
from collections import defaultdict

mem = [defaultdict(int) for _ in range(0,1441)]

def processPostAtMin(minutes, post):
    processed = set()
    for token in post.split(' '):
        if token.startswith('#') and token not in processed:
            mem[minutes][token] += 1
            processed.add(token)

# preprocess all posts
for line in sys.stdin:
    minutes = int(line.strip())
    post = sys.stdin.readline().strip()
    blank = sys.stdin.readline()
    processPostAtMin(minutes, post)

# init sliding window
maxPopularHt = ''
maxHourlyPop = -1
window = defaultdict(int)
for i in range(1440, 1440-60, -1):
    hashtagsAtTime = mem[i]
    for hashtag, times in hashtagsAtTime.items():
        window[hashtag] += times
        # update the most popular hashtag in an hour (if need)
        if window[hashtag] > maxHourlyPop:
            maxPopularHt = hashtag
            maxHourlyPop = window[hashtag]
            # print(maxPopularHt)

# slide the window right to left
for i in range(1380, -1, -1):
    toAdd = mem[i]
    toDeduct = mem[i+60]
    for hashtag, times in toDeduct.items():
        window[hashtag] -= times
    for hashtag, times in toAdd.items():
        window[hashtag] += times
        if window[hashtag] > maxHourlyPop:
            maxPopularHt = hashtag
            maxHourlyPop = window[hashtag]
            # print(maxPopularHt)

with open('output2.txt', 'w') as outputFile:
    outputFile.write(maxPopularHt)