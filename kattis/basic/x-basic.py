import sys

digits = {'0','1','2','3','4','5','6','7','8','9'}
allowed = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'}

def isNumericHex(number):
    for c in number:
        if c not in allowed:
            return False
    return True

N = int(input())
for _ in range(N):
    ok = True
    tokens = input().split("#")
    # print(tokens)
    for i in range(0, len(tokens), 2):
        if i >= len(tokens)-1: break
        base, num = tokens[i].strip(), tokens[i+1].strip()

        # empty base means bsae 10 digit
        if not base:
            if len(num) == 0:
                ok = False
                break  

            if not num.isnumeric():
                ok = False
                break
        else:
            if len(base) == 0 or len(num) == 0:
                ok = False
                break  

            # number only may contain digits
            if not isNumericHex(num):
                ok = False
                break

            if not isNumericHex(base):
                ok = False
                break

            try:
                base = int(base, 10)
            except:
                try:
                    base = int(base, 16)
                except:
                    ok = False
                    break

            if base < 2 or base > 16:
                ok = False
                break

            # number must be convertible to the base
            try:
                x = int(num, base)
            except:
                ok = False
                break

    if ok: print("yes")
    else: print("no")