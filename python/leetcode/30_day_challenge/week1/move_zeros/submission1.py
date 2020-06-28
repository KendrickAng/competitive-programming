from Lib.typing import List

# O(N) time, O(N) space
def moveZeros(nums: List[int]) -> None:
    nonZeros = []
    zeroCount = 0
    for num in nums:
        if num == 0:
            zeroCount += 1
        else:
            nonZeros.append(num)
    for i in range(len(nonZeros)):
        nums[i] = nonZeros[i]
    for i in range(len(nonZeros), len(nonZeros) + zeroCount):
        nums[i] = 0

nums = [0,1,0,3,12]
moveZeros(nums)
print(nums)