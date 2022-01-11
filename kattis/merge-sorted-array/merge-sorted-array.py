class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        arr = []
        left = 0
        right = 0
        
        while left < m or right < n:
            leftEle = nums1[left] if left < m else float('inf')
            rightEle = nums2[right] if right < n else float('inf')
            if leftEle < rightEle:
                arr.append(leftEle)
                left += 1
            else:
                arr.append(rightEle)
                right += 1
                
        for i, num in enumerate(arr):
            nums1[i] = num
            