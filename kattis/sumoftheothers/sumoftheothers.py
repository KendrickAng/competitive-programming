import sys

for line in sys.stdin:
    tokens = list(map(int, line.split()))
    a = sum(tokens)
    for token in tokens:
        if a - token == token:
            print(token)
            break