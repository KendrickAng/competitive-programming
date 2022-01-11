ans = {((x ^ (x << 1)) & 255): x for x in range(0, 256)}
n = int(input())
aa = list(map(int, input().split()))
bb = [str(ans[a]) for a in aa]
print(" ".join(bb))