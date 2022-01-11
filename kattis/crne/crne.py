import math

n = int(input())
a = math.ceil((n+1)/2)
if (n % 2 != 0):
    b = a + 1 
else:
    b = a
print(a * b)