tokens = input().split()
a = float(tokens[0])
b = tokens[1]
c = tokens[3]

m1 = ["th", "in", "ft", "yd", "ch", "fur", "mi", "lea"]
m2 = ["thou", "inch", "foot", "yard", "chain", "furlong", "mile", "league"]

bi = -1
ci = -1
for i in range(len(m1)):
    if m1[i] == b or m2[i] == b:
        bi = i
    if m1[i] == c or m2[i] == c:
        ci = i

con = [1, 1000, 12, 3, 22, 10, 8, 3]
if bi <= ci:
    for i in range(bi+1, ci+1):
        a /= con[i]
else:
    for i in range(bi, ci, -1):
        a *= con[i]

print(a)