from functools import cmp_to_key

t = int(input())

SEP = "=============================="

def compare(a, b):
    a_rank = a[1]
    b_rank = b[1]
    for i in range(len(a_rank)):
        aa = a_rank[i]
        bb = b_rank[i]
        if aa != bb:
            if aa == "upper":
                return -1
            elif aa == "middle" and bb == "upper":
                return 1
            elif aa == "middle" and bb == "lower":
                    return -1
            elif aa == "lower":
                return 1
    if a[0] < b[0]:
        return -1
    elif a[0] > b[0]:
        return 1
    else:
        return 0 
            
for _ in range(t):
    n = int(input())
    arr = []
    for i in range(n):
        tokens = input().split()
        name = tokens[0][:-1]
        rank = tokens[1].split('-')[::-1]
        for j in range(10-len(rank)):
            rank.append("middle")

        arr.append((name, rank))

    arr.sort(key=cmp_to_key(compare))
    for name, rank in arr:
        print(name)
    print(SEP)