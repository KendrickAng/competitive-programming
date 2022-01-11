class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        power = 0
        ans = 0
        for c in columnTitle[::-1]:
            ans += pow(26, power) * (ord(c) - ord("A") + 1)
            power += 1
        return ans