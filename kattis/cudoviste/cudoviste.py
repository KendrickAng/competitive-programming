r, c = list(map(int, input().split()))
arr = []
for _ in range(r):
    arr.append([x for x in input()])

BUILDING = "#"
CAR = "X"
PARKING = "."

zero = 0
one = 0
two = 0
three = 0
four = 0
# solve
for ri in range(r-1):
    for ci in range(c-1):
        tl = arr[ri][ci]
        tr = arr[ri][ci+1]
        bl = arr[ri+1][ci]
        br = arr[ri+1][ci+1]
        if tl == BUILDING or tr == BUILDING or bl == BUILDING or br == BUILDING:
            continue
        squashed = sum([1 for x in [tl,tr,bl,br] if x == CAR])
        if squashed == 1:
            one += 1
        elif squashed == 2:
            two += 1
        elif squashed == 3:
            three += 1
        elif squashed == 4:
            four += 1
        elif squashed == 0:
            zero += 1
print(zero)
print(one)
print(two)
print(three)
print(four)