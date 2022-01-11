class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        times = 0
        memo = defaultdict(int)

        def dp(target):
            if target == 0:
                return 1
            
            if memo.get(target) is None:
                tmp = 0
                for num in nums:
                    if num <= target:
                        tmp += dp(target - num)
                memo[target] = tmp
            
            return memo[target]

        return dp(target)
    
"""
1 2 3 target = 4
1 1 1 1
1 1 2
1 2 1
1 3
2 1 1
2 2
3 1
7 ways

9 target = 3
0

times = 0
memo = defaultdict(int)

def dp(target):
    if target == 0:
        return 1
    if memo.get(target) is None:
    
return dp(target)
"""