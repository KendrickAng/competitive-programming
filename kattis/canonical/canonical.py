def greedy(coins, amt):
    used = []
    for i in range(len(coins)):
        coin = coins[i]
        used.append(0)
        while coin <= amt:
            used[i] += 1
            amt -= coin
    return used

def minimal(vec, j):
    ret = [0] * len(vec)
    for i in range(len(vec)):
        if i <= j:
            ret[i] = vec[i]
    ret[j] += 1
    return ret

def canonical(coins):
    # print(f"\ntesting {coins}")
    coins.sort(reverse=True)
    for i in range(1, len(coins)):
        for j in range(i, len(coins)):
            # print(f"{i} {j}")
            gvec = greedy(coins, coins[i-1]-1)
            mw = minimal(gvec, j)
            dotprod = sum([mw[i] * coins[i] for i in range(len(coins))])
            gvec2 = greedy(coins, dotprod)
            # print(f"gvec: {gvec} mw: {mw} gvec2: {gvec2}")
            if sum(gvec2) > sum(mw):
                return False
    return True

n = int(input())
coins = list(map(int, input().split()))
if canonical(coins):
    print("canonical")
else:
    print("non-canonical")
