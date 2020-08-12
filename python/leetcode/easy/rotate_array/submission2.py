from Lib.typing import List

# O(N) time, O(N) space
def rotate(nums: List[int], k: int) -> None:
    """
    Do not return anything, modify nums in-place instead.
    Idea: Use a temp variable to keep track of the replaced element.
    First replace all elements cycle % k = 0, then cycle % k = 1 ... cycle % k = k-1
    Once we reach back cycle % k = 0, all the elements will have been sorted.
    """
    n = len(nums)
    k = k % n

    # TODO: account for the case where you cycle back to an already replaced index, causing infinite loop
    for i in range(n):
        cycle = i
        toReplaceWith = nums[cycle]

        while True:

            # cycle and replace
            cycle = (cycle + k) % n
            temp = nums[cycle]
            nums[cycle] = toReplaceWith

            toReplaceWith = temp

            if cycle == i:
                nums[cycle] = toReplaceWith
                break


arr = [1,2,3,4,5,6,7]
rotate(arr, 3)
print(arr) # [5,6,7,1,2,3,4]
