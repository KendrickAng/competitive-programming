n = int(input())

def is_villian(c):
    return c == 't' or c == 'j' or c == 'b'

def is_object(c):
    return c == '$' or c == '|' or c == '*'

for _ in range(n):
    line = input()
    stack = []
    ok = True
    ejected = False
    for c in line:
        if is_villian(c):
            if not stack:
                ejected = True
                break
            item = stack.pop()
            if (c == 'b' and item != '$' or
                c == 't' and item != '|' or
                c == 'j' and item != '*'):
                ejected = True
                break
        elif is_object(c):
            stack.append(c)
        else:
            pass

    if len(stack) <= 0 and not ejected:
        ok = True
    else:
        ok = False
    
    if ok:
        print("YES")
    else:
        print("NO")
