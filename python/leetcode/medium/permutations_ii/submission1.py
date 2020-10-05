from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def permutations(myNums):
            if not myNums:
                return [[]]
            newPerms = []
            for i in range(len(myNums)):
                e = myNums[i]
                newNums = myNums[:i] + myNums[i+1:]
                newPerms.extend(map(lambda x: x + [e], permutations(newNums)))
            return newPerms
        return list(map(list, set(map(tuple, permutations(nums)))))

sln = Solution()
print(sln.permuteUnique([1,1,2]))