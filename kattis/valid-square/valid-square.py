import math

class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        def helper(p1, p2, p3, p4):
            def dist(a, b):
                x = abs(a[0] - b[0])
                y = abs(a[1] - b[1])
                return sqrt(x * x + y * y)

            d1 = dist(p1, p2)
            d2 = dist(p1, p3)
            d3 = dist(p1, p4)
            if d1 == 0 or d2 == 0 or d3 == 0:
                return False

            arr = sorted([d1, d2, d3])

            return arr[0] == arr[1] and math.isclose(arr[2], arr[0] * math.sqrt(2))
        
        ans = True
        for a, b, c, d in itertools.permutations([p1,p2,p3,p4]):
            ans = ans and helper(a,b,c,d)
        
        return ans