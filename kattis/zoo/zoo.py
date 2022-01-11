from collections import defaultdict

n = int(input())
list_num = 1
while n != 0:
    counter = defaultdict(int)
    
    for _ in range(n):
        kind = input().split()[-1].lower()
        counter[kind] += 1

    print(f"List {list_num}:")
    for key in sorted(counter.keys()):
        print(f"{key} | {counter[key]}")

    list_num += 1
    n = int(input())