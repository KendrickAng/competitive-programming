from sys import stdin

def min_moves(n: int, s: int):
    moves = 0
    power = 1
    while sum(map(int, str(n))) > s:
        d = (n // power) % 10
        toAdd = power * (10-d)
        moves += toAdd
        n += toAdd
        power *= 10
    return moves

t = int(stdin.readline())
for _ in range(t):
    n, s = map(int, stdin.readline().split())
    print(min_moves(n, s))