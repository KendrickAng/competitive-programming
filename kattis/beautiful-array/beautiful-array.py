class Solution:
    def beautifulArray(self, n: int) -> List[int]:
        memo = {1: [1]}
        def recurse(N):
            if N not in memo:
                odds = recurse((N+1)//2)
                evens = recurse(N//2)
                memo[N] = [2*x-1 for x in odds] + [2*x for x in evens]
            return memo[N]
        return recurse(n)
                
    
"""
2 1 4 3

1 2 3 4

3 1 2 5 4

1 2 3 4 5

n = 1
1

n = 2
1 2

n = 3
1 3 2

n = 4
1 2 3 4
1 3 4 2

1 3 4 2

1 3 2

1 3 2 4

1 3 5 2 4 6
"""