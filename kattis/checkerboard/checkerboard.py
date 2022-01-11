n = int(input())
arr = []
for _ in range(n):
    arr.append([x for x in input()])

correct = True
# check rows
for row in arr:
    black = 0
    white = 0
    for cell in row:
        if cell == "W":
            white += 1
        elif cell == "B":
            black += 1
    three_consec = False
    for i in range(len(row)-2):
        if row[i] == row[i+1] == row[i+2]:
            three_consec = True
    if black != white or three_consec:
        correct = False

if not correct:
    print(0)
    exit(0)

# check columns
for ci in range(len(arr[0])):
    white = 0
    black = 0
    for ri in range(len(arr)):
        if arr[ri][ci] == "W":
            white += 1
        elif arr[ri][ci] == "B":
            black += 1
    three_consec = False
    for ri in range(len(arr)-2):
        if arr[ri][ci] == arr[ri+1][ci] == arr[ri+2][ci]:
            three_consec = True
    if black != white or three_consec:
        correct = False

if not correct:
    print(0)
else:
    print(1)