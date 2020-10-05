import sys

def solve(lineArr):
    if not lineArr:
        return 0
    result = int(lineArr[0])
    for i in range(1, len(lineArr), 2):
        operator = lineArr[i]
        digit = int(lineArr[i+1])
        if operator == '-':
            result -= digit
        elif operator == '+':
            result += digit
    return result

ret = []
for line in sys.stdin:
    lineArr = line.split()
    ret.append(solve(lineArr))

with open('input2.txt', 'w') as file:
    file.writelines(' '.join(map(str, ret)))
