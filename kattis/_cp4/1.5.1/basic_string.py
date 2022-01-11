import sys

lines = []

def first_block():
    while True:
        line = input()
        if line[:7] == ".......":
            break
        yield line

# print(' '.join(first_block()))
print(sys.stdin.read().splitlines())