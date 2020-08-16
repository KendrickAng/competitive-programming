from collections import defaultdict

class Solution:
    def numSplits(self, s: str) -> int:
        n = len(s)
        ret = 0
        left = defaultdict(int)
        right = defaultdict(int)
        for letter in s:
            right[letter] += 1

        for i in range(n):
            if i != 0 and i != n and len(left) == len(right):
               ret += 1
            left[s[i]] += 1
            right[s[i]] -= 1
            if right[s[i]] == 0:
                del right[s[i]]

        return ret

sln = Solution()
print(sln.numSplits("aacaba")) # 2
print(sln.numSplits("abcd")) # 1
print(sln.numSplits("aaaaa")) # 4
print(sln.numSplits("acbadbaada")) # 2