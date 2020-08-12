# Idea: Start from base cases, then work upwards from there.
def checkValidString(s: str) -> bool:
    if not s:
        return True

    n = len(s)
    dp = [[False for i in range(n)] for j in range(n)]
    LEFTY = "(*"
    RIGHTY = "*)"

    # base cases - string of length 1
    for i in range(n):
        if s[i] == '*':
            dp[i][i] = True
        if i < n-1 and s[i] in LEFTY and s[i+1] in RIGHTY:
            dp[i][i+1] = True

    # building up cases, for every string of length 2 and above:
    # Case 1: s[i] == '*' and dp[i+1][j] == True -> dp[i][j] = True
    # Case 2: s[i] == '(' and there exists some k s.t dp[i][k] = True, and the interval dp[i][k-1], dp[k+1][j] = True
    #   E.g * .... * ...
    #   E.g ( .... * ...
    for size in range(2, n):
        for i in range(n - size):
            if s[i] == '*' and dp[i+1][i + size]:
                dp[i][i + size] = True
            elif s[i] in LEFTY:
                for k in range(i+1, i+size+1):
                    if s[k] in RIGHTY and (k == i+1 or dp[i+1][k-1]) and (k == i+size or dp[k+1][i+size]):
                        dp[i][i+size] = True

    return dp[0][-1]

print(checkValidString("()(***")) # true
print(checkValidString("(*))")) # true
print(checkValidString("))((")) # false