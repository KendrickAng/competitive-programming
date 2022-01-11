arr = input().split(";")
ans = 0
for a in arr:
    if "-" in a:
        aa, bb = list(map(int, a.split("-")))
        ans += bb - aa + 1
    else:
        ans += 1
print(ans)