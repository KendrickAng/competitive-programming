class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pToS = {}
        n = len(position)
        for i in range(n):
            pToS[position[i]] = speed[i]
        
        position.sort(reverse=True)
        time = [(target-pos) / pToS[pos] for pos in position]
        
        ans = 1
        localMax = None
        for t in time:
            if localMax is None:
                localMax = t
            elif t <= localMax:
                pass # do nothing
            elif t > localMax:
                ans += 1
                localMax = t
                
        return ans        
        
    
"""
12
10 8 0 5 3 - position
2  4 1 1 3 - speed

12 12 1 6 6 - one fleet
12 12 2 7 7
12 12 3 8 8
...
12 12 7 12 12 - two fleets
...
12 12 12 12 12 - three fleets

- all values of position are unique (at the start)
"""