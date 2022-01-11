n = int(input())
arr = []
for _ in range(n):
    a, b = list(map(int, input().split()))
    for i in range(a, b):
        arr.append((a, b))

for i in range(len(arr)):
    for j in range(i+1, len(arr)):
        if arr[i][1] < arr[j][0] or arr[i][0] > arr[j][1]:
            print("edward is right")
            exit(0)
print("gunilla has a point")

