"""
O(n^3) solution, too slow
"""
def substrCount(n, s):
    """
    :param n: length of string s
    :param s: string s
    """
    def isSpecial(str):
        c = str[0]
        if len(str) % 2 == 0:
            for ch in str:
                if ch != c:
                    return False
        else:
            for i in range(len(str)):
                if i == len(str) // 2:
                    continue
                if str[i] != c:
                    return False
        return True

    count = 0
    # try all possible lengths of substrings
    for length in range(1, n):
        for start in range(0, n-length+1):
            substring = s[start:start+length]
            if isSpecial(substring):
                count += 1
    return count

print(substrCount(7, "abcbaba"))
print(substrCount(5, "asasd"))