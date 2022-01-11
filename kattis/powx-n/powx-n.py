class Solution:
    def myPow(self, x: float, n: int) -> float:
        #print(n)
        if abs(n) <= 2:
            return pow(x, n)

        if n % 2 == 0:
            return self.myPow(self.myPow(x, n//2), 2)
        else:
            return x * self.myPow(self.myPow(x, (n-1)//2) , 2)    
"""

a ^ x
if x is even - (a ^ x/2)^2
if x is odd - a(a ^ (x-1)/2)^2

if abs(n) < 10:
    return pow(x, n)

if x % 2 == 0:
    return myPow(myPow(x, n//2), 2)
else:
    return x * myPow(myPow(x, (x-1)//2) , 2)
"""