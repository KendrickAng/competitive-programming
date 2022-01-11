s = input()

# first policy
ans = 0
for c in s:
    if c == 'D':
        ans += 2
if s[:2] == "DU":
    ans -= 1
elif s[:2] == "DD":
    ans -= 3
print(ans)

# second policy
ans = 0
for c in s:
    if c == 'U':
        ans += 2
if s[:2] == "UU":
    ans -= 3
elif s[:2] == "UD":
    ans -= 1
print(ans)

# third policy
ans = 0
for i in range(1, len(s)):
    if s[i-1] != s[i]:
        ans += 1
print(ans)
