# Doesn't work - O(n^3)
class Solution:
    # brute force approach
    def countSubstrings(self, s: str) -> int:
        ret = 0
        n = len(s)
        # for every possible string length
        for i in range(1, n+1):
            # form a substring of that length, check if palindrome.
            for j in range(0, n-i+1):
                subString = s[j:j+i]
                if self.isPalindrome(subString):
                    ret += 1
        return ret

    def isPalindrome(self, s: str):
        if len(s) <= 1:
            return True

        for i in range(len(s)):
            if s[i] != s[len(s) - i - 1]:
                return False
        return True

sl = Solution()
print(sl.countSubstrings("aaa"))
print(sl.isPalindrome("aaa"))
print(sl.isPalindrome("repaper"))
print(sl.isPalindrome("lemon"))