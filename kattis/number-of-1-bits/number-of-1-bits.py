class Solution:
    def hammingWeight(self, n: int) -> int:
        binStr = f"{n:b}"
        ans = 0
        for c in binStr:
            if c == '1': ans += 1
        return ans