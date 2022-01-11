from itertools import combinations

cards = list(map(int, input().split()))

# check for impossible or not
solvable = True
tmp = 0
for card in cards:
    if card != 0:
        tmp += 1

k = int(input())
if tmp < k:
    solvable = False

if solvable:
    idxs = [0,1,2,3,4,5,6,7,8,9]
    slns = 0
    combs = combinations(idxs, k)
    for comb in combs:
        t = 1
        for idx in comb:
            t *= cards[idx]
        slns += t
    print(slns)
else:
    print(0)


