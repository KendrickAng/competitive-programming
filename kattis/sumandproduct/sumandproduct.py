LIMIT = 1e10

n = int(input())
nums = list(map(int, input().split()))

sums = [0] * (n+1)
mults = [0] * (n+1)

mults[0] = 1
for i in range(len(nums)):
    num = nums[i]
    sums[i+1] = sums[i] + num
    mults[i+1] = mults[i] * num if (mults[i] == -1 or mults[i] < LIMIT) else -1

nMax = len(sums)
ans = 0
for j in range(2, nMax):
    if mults[j] == -1: break
    for i in range(0, j-1):
        sumRange = sums[j] - sums[i]
        multRange = mults[j] // mults[i]
        if sumRange == multRange: ans += 1

print(ans)