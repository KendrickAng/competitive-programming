"""
Dynamic programming. Couldn't solve question.
"""

def longestArithmeticSequence(arr):
    if len(arr) <= 1:
        return 1

    arr_d = [arr[i] - arr[i-1] for i in range(1, len(arr))]
    print(arr_d)

    ans = 0
    i = 0
    while i < len(arr_d):
        seq_len = 0
        to_match = arr_d[i]
        while i < len(arr_d) and arr_d[i] == to_match:
            seq_len += 1
            i += 1
        ans = max(ans, seq_len)
    return ans

print(longestArithmeticSequence([9,4,7,2,10]))
