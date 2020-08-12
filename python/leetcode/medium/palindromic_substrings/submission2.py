# WRONG SOLUTION - COMPLETELY OFF!!!

# Idea: dynamic programming
# Keep a two-level dictionary with first key - length, second key - start position
# For every even length substring of length n, if both substrings of n/2 are palindrome -> is palindrome
# For every odd length substring of length n, if both substrings of floor(n/2) are palindromes -> is a palindrome
class Solution:
    mem = {}

    def countSubstrings(self, s: str) -> int:
        ret = 0
        n = len(s)

        for ssLen in range(1, n+1):
            for startIdx in range(0, n-ssLen+1):
                n2 = ssLen // 2

                # even case
                if ssLen % 2 == 0:
                    isLeftPalindrome = self.checkPalindrome(s, n2, startIdx)
                    isRightPalindrome = self.checkPalindrome(s, n2, startIdx+n2)
                    if isLeftPalindrome and isRightPalindrome:
                        ret += 1

                # odd case
                if ssLen % 2 != 0:
                    isLeftPalindrome = self.checkPalindrome(s, n2, startIdx)
                    isRightPalindrome = self.checkPalindrome(s, n2, startIdx+n2+1)
                    if isLeftPalindrome and isRightPalindrome:
                        ret += 1
        return ret

    def checkPalindrome(self, s: str, n: int, startIdx: int) -> bool:
        if n in self.mem and startIdx in self.mem[n]:
            return self.mem[n][startIdx]
        else:
            if n not in self.mem:
                self.mem[n] = {}

            isPal = self.isPalindrome(s[startIdx:startIdx+n])
            self.mem[n][startIdx] = isPal
            return isPal

    def isPalindrome(self, s: str):
        if len(s) <= 1:
            return True

        for i in range(len(s)):
            if s[i] != s[len(s) - i - 1]:
                return False
        return True

sl = Solution()
print(sl.countSubstrings("aaa")) # 6
print(sl.countSubstrings("abc")) # 3
print(sl.countSubstrings("aba")) # 4