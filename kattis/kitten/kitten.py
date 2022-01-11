from collections import defaultdict

k = int(input())
tokens = list(map(int, input().split()))
tree = {}
while tokens[0] != -1:
    for node in tokens[1:]:
        tree[node] = tokens[0]
    tokens = list(map(int, input().split()))

# generate answer
ans = []
tmp = k
while tmp is not None:
    ans.append(str(tmp))
    tmp = tree.get(tmp, None)
print(" ".join(ans))