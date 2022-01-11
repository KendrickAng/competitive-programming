a = [1,2,4,6,10,12,16,18]
b = [2,3,5,7,11,13,17,19]

# mult stores the number of inc before the a +1 causes the current register inc by 1
# should be [1,2,6...]
tmp = 1
mult = []
for num in b:
    mult.append(tmp)
    tmp *= num

curr = list(map(int, input().split()))

total = 0
for i in range(len(curr)):
    num = curr[i]
    total += (a[i] - curr[i]) * mult[i]

print(total)