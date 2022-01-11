l = int(input())
line = input()
stack = []

is_ok = True
bad_idx = -1
for i in range(l):
    c = line[i]
    if c == ' ':
        continue
    elif c == ')' or c == ']' or c == '}':
        if not stack:
            is_ok = False
            bad_idx = i
            break
        nxt = stack.pop()
        if ((c == ')' and nxt != '(') or
            (c == ']' and nxt != '[') or 
            (c == '}' and nxt != '{')):
            is_ok = False
            bad_idx = i
            break 
    else:
        stack.append(c) # opening bracket

if is_ok:
    print("ok so far")
else:
    print(f"{line[bad_idx]} {bad_idx}")