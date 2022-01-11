from collections import defaultdict

n = int(input())
notes = set(input().split())
mnotes = ["A","A#","B","C","C#","D","D#","E","F","F#","G","G#"]
offset = [0,2,4,5,7,9,11,12]

# fill dict
a = defaultdict(set)
for b in range(len(mnotes)):
    for c in offset:
        a[mnotes[b]].add(mnotes[(b+c)%len(mnotes)])

# check against dict
ans = []
for key, val in a.items():
    if notes.difference(val) == set():
        ans.append(key)

if ans:
    print(" ".join(ans))
else:
    print("none")
    
