class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        def merge(left, right):
            ret = []
            l = 0
            r = 0
            while l < len(left) or r < len(right):
                lElement = left[l] if l < len(left) else float('inf')
                rElement = right[r] if r < len(right) else float('inf')
                if lElement < rElement:
                    ret.append(lElement)
                    l += 1
                else:
                    ret.append(rElement)
                    r += 1
            return ret
            
        # find the idx of the first positive element
        n = len(nums)
        i = 0
        while i < n and nums[i] < 0:
            i += 1
        
        # split the array 
        left = nums[:i]
        right = nums[i:]
        left.reverse()
        left = [num ** 2 for num in left]
        right = [num ** 2 for num in right]
        
        # merge both arrays in O(n)
        return merge(left, right)