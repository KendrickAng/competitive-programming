import sys
from collections import defaultdict

mem = defaultdict(int)

def process(line):
    if not line:
        return
    tokens = line.rstrip().split(' ')
    processed = set()
    for token in tokens:
        if token.startswith('#') and token not in processed:
            mem[token] += 1
            processed.add(token)

for line in sys.stdin:
    minutes = line
    post = sys.stdin.readline()
    blank = sys.stdin.readline()
    process(post)

bestHashtag = ''
bestNum = -1
for hashtag, appearances in mem.items():
    if appearances > bestNum:
        bestNum = appearances
        bestHashtag = hashtag

with open('output2.txt', 'w') as outputFile:
    outputFile.write(bestHashtag)

