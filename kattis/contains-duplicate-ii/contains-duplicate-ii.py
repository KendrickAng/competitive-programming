class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        # init our sliding window
        left = 0
        right = 0
        n = len(nums)
        inWindow = set() # elemmtns in window

        while right < n:
            num = nums[right]

            if right <= k:
                # add elements while checking
                if num in inWindow:
                    return True
                inWindow.add(num)
            else:

                # move window to maintain size
                toRemove = nums[left]
                inWindow.discard(toRemove)
                left += 1

                # check
                if num in inWindow:
                    return True
                inWindow.add(num)

            right += 1

        return False
        
"""
1 2 3 1
k = 3

0, 3

1 0 1 1
2, 3

1 2 3 1 2 3
k = 2
x false

set to detect if item in set already

# init our sliding window
left = 0
right = 0
n = len(nums)
inWindow = set() # elemmtns in window

while right < n:
    num = nums[right]
    
    if right <= k:
        # add elements while checking
        if num in inWindow:
            return True
        inWindow.add(num)
    else:

        # move window to maintain size
        toRemove = nums[left]
        inWindow.discard(toRemove)
        left += 1
        
        # check
        if num in inWindow:
            return True
        inWindow.add(num)
        
    right += 1

return False
"""