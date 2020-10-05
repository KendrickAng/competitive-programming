import sys
from collections import defaultdict

mem = defaultdict(int)

def process(line):
    if not line:
        return
    tokens = line.rstrip().split(' ')
    for token in tokens:
        if token.startswith('#'):
            mem[token] += 1

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

