testcases = int(input())

for _ in range(testcases):
    n, m = list(map(int, input().split()))

    class Prize:
        def __init__(self, stickers, value):
            self.stickers = stickers
            self.value = value

    prizes = []
    for _ in range(n):
        tokens = input().split()
        k = int(tokens[0])
        stickers = list(map(int, tokens[1: 1+k]))
        value = int(tokens[-1])
        prizes.append(Prize(stickers, value))

    tokens = list(map(int, input().split()))
    stickers = {i+1: tokens[i] for i in range(len(tokens))}

    ans = 0
    for prize in prizes:
        purchases = min([stickers[x] for x in prize.stickers])
        for x in prize.stickers:
            stickers[x] -= purchases
        ans += prize.value * purchases
        # stop = False

        # while not stop:
        #     canbuy = True
        #     for s in prize.stickers:
        #         if s not in stickers or stickers[s] <= 0:
        #             canbuy = False
        #     if canbuy:
        #         ans += prize.value
        #         stop = False
        #         for s in prize.stickers:
        #             stickers[s] -= 1
        #     else:
        #         stop = True
    print(ans)