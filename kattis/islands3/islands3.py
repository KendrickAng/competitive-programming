r, c = list(map(int, input().split()))
arr = []
for _ in range(r):
    arr.append([x for x in input()])

def flood(arr, rr, cc):
    if rr >= 0 and rr < len(arr) and cc >= 0 and cc < len(arr[0]):
        if arr[rr][cc] == 'L' or arr[rr][cc] == 'C':
            arr[rr][cc] = 'W'
            flood(arr, rr-1, cc) # up
            flood(arr, rr+1, cc) # down
            flood(arr, rr, cc-1) # left
            flood(arr, rr, cc+1) # right
        
ans = 0

for ri in range(r):
    for ci in range(c):
        if arr[ri][ci] == 'L':
            flood(arr, ri, ci)
            ans += 1

print(ans)