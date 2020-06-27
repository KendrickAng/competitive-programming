def longestArithmeticSequence(A):
    n:int = len(A)
    ret:int = 2
    dp = [{}] * n

    # consider all indices
    for i in range(1, n):
        currNum:int = A[i]
        # consider each step size up to i
        for j in range(0, i):
            diff:int = currNum - A[j]
            if diff not in dp[j]:
                dp[i][diff] = 2
            else:
                dp[i][diff] = dp[j][diff] + 1
                ret = max(ret, dp[i][diff])
    return ret

print(longestArithmeticSequence([20,1,15,3,10,5,8]))