def getKth(lo, hi, k):
    def calcPower(num):
        power = 0
        while num > 1:
            power += 1
            if num % 2 == 0:
                num = num / 2
            else:
                num = 3 * num + 1
        return power

    if lo == hi:
        return lo

    powerNumber = []
    for num in range(lo, hi + 1):
        powerNumber.append((calcPower(num), num))
    # sort by power
    powerNumber.sort(key=lambda x: x[0])
    return powerNumber[k-1][1]


print(getKth(12, 15, 2))
print(getKth(1, 1, 1))
print(getKth(7, 11, 4))