class Solution:
    def reverseBits(self, n: int) -> int:
        string = f"{n:032b}"
        return int(string[::-1], 2)