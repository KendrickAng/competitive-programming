import math

def maxMin(k, arr):
    arr.sort()
    ans = math.inf
    for i in range(len(arr)-k+1):
        ans = min(ans, arr[i+k-1] - arr[i])
    return ans

print(maxMin(3, [10,100,300,200,1000,20,30]))
print(maxMin(4, [1,2,3,4,10,20,30,40,100,200]))
print(maxMin(2, [1,2,1,2,1]))