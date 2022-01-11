class Solution:
    def countBits(self, n: int) -> List[int]:
        def countOnes(x):
            ones = 0
            while x > 0:
                if (x & 1) == 1:
                    ones += 1
                x >>= 1
            return ones
        
        return [countOnes(x) for x in range(n+1)]
    
"""
0 1 1
0 - 0
1 - 1
10 - 1


"""