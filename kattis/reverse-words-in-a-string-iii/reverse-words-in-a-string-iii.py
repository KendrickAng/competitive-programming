class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        return " ".join([w[::-1] for w in words])
        