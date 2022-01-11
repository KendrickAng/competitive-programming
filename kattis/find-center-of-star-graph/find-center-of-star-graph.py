class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        first = edges[0]
        second = edges[1]
        for n1 in first:
            for n2 in second:
                if n1 == n2: return n1
        return -1