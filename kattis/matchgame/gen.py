import random
import string

def genRan(n):
    ret = ""
    for i in range(n):
        ret += random.choice(string.digits)
    return ret

stuff = []
for i in range(1, 13):
    count = 0
    while count <= 100:
        a = genRan(i)
        b = genRan(i)
        if a == b: continue
        stuff.append(f"{a} {b}\n")
        count += 1

with open("gen.txt", "w") as file:
    file.writelines(stuff)