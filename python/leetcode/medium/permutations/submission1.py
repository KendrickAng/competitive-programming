def permute(nums):
    if len(nums) <= 1:
        return [nums]
    ans = []
    for i in range(len(nums)):
        rest = nums[:i] + nums[i+1:]
        for arr in permute(rest):
            ans.append([nums[i]] + arr)
    return ans

print(permute([1,2,3]))