n = int(input())
probs = []
for _ in range(n):
    tokens = input().split()
    probs.append(float(tokens[1]))
probs.sort()
probs.reverse()
count = 1
ans = 0
for prob in probs:
    ans += count * prob
    count += 1
print(ans)