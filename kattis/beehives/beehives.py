import math

tmp = input().split()
d = float(tmp[0])
n = int(tmp[1])

class Hive:
    def __init__(self, x, y, is_sour):
        self.x = x
        self.y = y
        self.is_sour = is_sour

def distance(h1, h2):
    x_off = abs(h1.x - h2.x)
    y_off = abs(h1.y - h2.y)
    return math.sqrt(x_off * x_off + y_off * y_off)

while d != 0.0 and n != 0:
    hives = []
    
    for _ in range(n):
        x, y = list(map(float, input().split()))
        hives.append(Hive(x, y, False))

    for i in range(len(hives)):
        for j in range(i+1, len(hives)):
            a = hives[i]
            b = hives[j]
            if distance(a, b) <= d:
                a.is_sour = True
                b.is_sour = True

    sour = 0
    sweet = 0
    for h in hives:
        if h.is_sour:
            sour += 1
        else:
            sweet += 1
    print(f"{sour} sour, {sweet} sweet")


    tmp = input().split()
    d = float(tmp[0])
    n = int(tmp[1])
