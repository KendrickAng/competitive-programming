from collections import defaultdict

m, n = list(map(int, input().split()))
hpdict = defaultdict(int)

# fill the dict
for _ in range(m):
    tokens = input().split()
    hpdict[tokens[0]] = int(tokens[1])

# job descriptions
for _ in range(n):
    line = input()
    points = 0

    while line != ".":
        linewords = line.split()
        for word in linewords:
            points += hpdict[word]
        line = input()
            
    print(points)
    