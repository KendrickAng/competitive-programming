from collections import deque
from sortedcontainers import SortedList
import heapq

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # bst = SortedList([1,4,2,3,5])
        # print(bst)
        # print(bst[0])
        # print(bst[-1])
        # print(bst.pop())

        left = 0
        right = 0
        n = len(nums)
        
        # window and bst
        q = deque()
        bst = SortedList()
        ans = []
        
        while right < n:
            num = nums[right]
            q.append(num)
            bst.add(num)
            
            if right < k-1:
                # window not initialized
                pass
            elif right == k-1:
                # calculate first ans
                ans.append(bst[-1])
            else:
                toRemove = q.popleft()
                bst.discard(toRemove)
                ans.append(bst[-1])

            right += 1
        
        return ans
"""
k <= 10^ 5
nums.length <= 10^5

1 3 -1 -3 5 3 6 7, k = 3
3 3 5 5 6

1, k =1
1

1, -1, k = 1
1 -1

9, 11, k = 2
11

4, -2, k = 2
4

observations:
- if k > nums.length no answer -> return []
- otherwise perform normal sliding window

deque to simulate sliding window?
get max? 

brute force:
maintain window as ddeque
as we move the window, recalc max from dequeu

dequque and pq
n log k - possible
"""