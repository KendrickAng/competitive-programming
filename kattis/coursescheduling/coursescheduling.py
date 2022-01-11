from collections import defaultdict

n = int(input())
c_to_name = defaultdict(set)

for _ in range(n):
    tokens = input().split()
    name = f"{tokens[0]} {tokens[1]}"
    course = tokens[2]
    c_to_name[course].add(name)

keys = sorted(list(c_to_name.keys()))
for key in keys:
    print(f"{key} {len(c_to_name[key])}")