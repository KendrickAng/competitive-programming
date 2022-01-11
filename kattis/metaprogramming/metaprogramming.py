import sys

mem = {}
for line in sys.stdin:
    tokens = line.split()
    if tokens[0] == "define":
        mem[tokens[2]] = int(tokens[1])
    elif tokens[0] == "eval":
        op = tokens[2]
        if tokens[1] not in mem or tokens[3] not in mem:
            print("undefined")
            continue
        if op == "<":
            if mem[tokens[1]] < mem[tokens[3]]:
                print("true")
            else:
                print("false")
        elif op == ">":
            if mem[tokens[1]] > mem[tokens[3]]:
                print("true")
            else:
                print("false")
        elif op == "=":
            if mem[tokens[1]] == mem[tokens[3]]:
                print("true")
            else:
                print("false")