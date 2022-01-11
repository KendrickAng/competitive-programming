n = int(input())
mountainHeights = list(map(int, input().split()))

peak = mountainHeights[0]
valley = mountainHeights[0]
ans = 0
for mountainHeight in mountainHeights:
    valley = min(valley, mountainHeight)
    if mountainHeight >= peak:
        ans = max(ans, peak - valley)
        peak = mountainHeight
        valley = mountainHeight
    else:
        ans = max(ans, mountainHeight - valley)

print(ans)