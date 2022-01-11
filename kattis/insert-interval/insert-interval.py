from operator import itemgetter

class Solution:
    def insertNewInterval(self, intervals, newInterval):
        intervals.append(newInterval)
        return sorted(intervals, key=itemgetter(0))
    
    def isOverlap(self, a, b):
        return b[0] <= a[1] and a[0] <= b[1]
    
    def mergeOverlapping(self, a, b):
        return [min(a[0], b[0]), max(a[1], b[1])]
    
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        # add new Interval
        intervals = self.insertNewInterval(intervals, newInterval)
        intervals.append([-10,-10])
        #print(intervals)
        ans = []
        for i in range(len(intervals)-1):
            ei = intervals[i]
            eii = intervals[i+1]
            if self.isOverlap(ei, eii):
                intervals[i+1] = self.mergeOverlapping(ei, eii)
            else:
                ans.append(ei)
        
        return ans
    
"""
1 2 2 4

sorted by starti in asc order
1,3 6,9 insert 2,5
1,5 - 1,3 + 2,5
6,9

1,2 3,5 6,7 8,10 12,16
4,8

1,2 
3,10 - 3,5 + 4,8 + 6,7 + 8,10
12, 16

[]
5,7

insert newInterval into intervals O(N)
add dummy [-10,-10]
for i in range(len(intervals))
    get element i
    get elemnt i + 1
    if canMerge(ei, ei+1)
        set elemnt i+1 to the merge(ei, ei+1)
    else:
        add element i to ans arr
return ans

cases:
overlapping intervals
non-overlapping intervals
interval consumed withtin another
duplicate intervals
"""