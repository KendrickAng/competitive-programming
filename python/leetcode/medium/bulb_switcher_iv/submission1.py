class Solution:
    # count the number of changes
    def minFlips(self, target: str) -> int:
        prev = target[0]
        flips = 0 if prev == "0" else 1
        for i in range(1, len(target)):
            if target[i] != prev:
                prev = target[i]
                flips += 1
        return flips

sln = Solution()
print(sln.minFlips("10111"))
print(sln.minFlips("00000"))
print(sln.minFlips("001011101"))