from operator import itemgetter

class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        def is_overlap(a, b):
            return a[0] < b[1] and b[0] < a[1]
        
        intervals.sort(key=itemgetter(0,1))
        for i in range(len(intervals)-1):
            if is_overlap(intervals[i], intervals[i+1]):
                return False
            
        return True
    
"""
0   5   10   15     20     30
"""