class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s + s)[1:-1]

sln = Solution()
print(sln.repeatedSubstringPattern("abab")) # True
print(sln.repeatedSubstringPattern("aba")) # False
print(sln.repeatedSubstringPattern("abcabcabcabc")) # True
print(sln.repeatedSubstringPattern("ababab")) # True