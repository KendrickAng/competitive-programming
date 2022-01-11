from sys import stdin, stdout
MOD = 1000000007

t = int(stdin.readline())
for case in range(t):
    n, k = list(map(int, stdin.readline().split()))
    s = stdin.readline().strip()

    ans = 0
    rem = ["" for _ in range(n)]
    
    tmp = 1
    multipliers = []
    for i in range((n+1) // 2):
        multipliers.append(tmp)
        tmp = (tmp * k) % MOD
    multipliers.reverse()

    for i in range((n + 1) // 2):
        c = s[i]
        smaller_chars = ord(c) - ord('a')

        ans += (smaller_chars * multipliers[i]) % MOD

        rem[i] = c
        rem[-(i+1)] = c

    if "".join(rem) < s:
        ans += 1

    stdout.write(f"Case #{case+1}: {ans % MOD}\n")
