import heapq
from math import floor

def minSum(num, k):
    # Write your code here
    if len(num) <= 0:
        return 0
    heap = [i * -1 for i in num]
    heapq.heapify(heap)
    for _ in range(k):
        largest = heapq.heappop(heap)
        heapq.heappush(heap, floor(largest/2))

    return -1 * sum(heap)

print(minSum([10,20,7], 4)) # 14
