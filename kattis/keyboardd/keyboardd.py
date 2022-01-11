# s = input()
# t = input()
# si = 0
# ti = 0
# ans = []
# count = 0

# print(s)
# print(t)
# while si < len(s) and ti < len(t):
#     if s[si] != t[ti]:
#         ans.append(t[ti])
#         ti += count
#         count = 0

#     count += 1
#     si += 1
#     ti += 1

# # last letter
# if si == len(s) and ti < len(t):
#     ans.append(t[ti])

# print("".join(list(dict.fromkeys(ans))))

from collections import Counter

s = input()
t = input()
sd = Counter(s)
td = Counter(t)
for key, val in sd.items():
    if td[key] == val * 2:
        print(key, end='')
print()