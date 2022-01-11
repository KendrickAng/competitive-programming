t = int(input())

for _ in range(t):
    n, m = list(map(int, input().split()))
    score = [0] * m

    for _ in range(n):
        line = input()
        for i in range(m):
            score[i] += int(line[i])

    ret = []

    for s in score:
        if s > n // 2:
            ret.append("1")
        else:
            ret.append("0")

    print("".join(ret))
