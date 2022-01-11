n = int(input())

for _ in range(n):
    tokens = input().split(",")
    tokens.reverse()
    pwr = 0
    total = 0
    for token in tokens:
        if token != "":
            total += int(token) * pow(60, pwr)
        pwr += 1
    print(total)