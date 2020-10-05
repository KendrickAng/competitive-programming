import collections
arr = []
x = input().split(" ")
width, height, n = x[0], x[1], x[2]
for _ in range(int(height)):
    s = input().split(" ")
    arr.append(s)


def micro_kitchen(arr):
    res = [[0 for _ in range(len(arr[0]))] for _ in range(len(arr))]
    result = [(0, 0)]
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            if arr[i][j] == 'o':
                bfs(arr, i, j, res)
    print(res)
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            if arr[i][j] == '.':
                if res[i][j] < res[result[0][1]][result[0][0]]:
                    result = [(j, i)]
                if res[i][j] == res[result[0][1]][result[0][0]]:
                    result.append((j, i))
    return sorted(list(set(result)))


def bfs(arr, i, j, res):
    q = collections.deque([(i, j, 0)])
    seen = {(i, j)}
    while q:
        r, c, dist = q.popleft()
        res[r][c] += dist
        for r1, c1 in {(r+1, c), (r, c-1), (r-1, c), (r, c+1)}:
            if 0 <= r1 < len(arr) and 0 <= c1 < len(arr[0]) and (r1, c1) not in seen and arr[r1][c1] == '.':
                q.append((r1, c1, dist+1))
                seen.add((r1, c1))


with open('test.txt', 'w') as out:
    out.write(str(micro_kitchen(arr)))