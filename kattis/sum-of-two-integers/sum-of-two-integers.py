class Solution:
    def getSum(self, a: int, b: int) -> int:
        x, y = abs(a), abs(b)
        if x < y: return self.getSum(b, a)
        sign = 1 if a > 0 else -1 # final sum of answer
        
        if a * b >= 0:
            # sum of two positive numbers (or sum of two negative numbers)
            while y:
                x, y = x ^ y, (x & y) << 1
        else:
            while y:
                x, y = x ^ y, ((~x) & y) << 1
                
        return x * sign
    
"""
1 2
01 10


"""