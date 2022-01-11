class Solution:
    def constructArr(self, height):
        # stack invariant: heights are decreasing
        stk = []
        leftTallerWall = []
        for h in height:
            # contains heights of bars in decreasing height
            while stk and stk[-1] <= h:
                stk.pop()
            
            # calculate left wall idx
            if not stk:
                leftTallerWall.append(-1)
            else:
                leftTallerWall.append(stk[0])
            stk.append(h)
           
        return leftTallerWall
    
    def constructArr2(self, height):
        stk = []
        rightTallerWall = []
        for h in height[::-1]:
            # contains heights of bars in decreasing height
            while stk and stk[-1] <= h:
                stk.pop()
            
            # calculate left wall idx
            if not stk:
                rightTallerWall.append(-1)
            else:
                rightTallerWall.append(stk[0])
            stk.append(h)
           
        rightTallerWall.reverse()
        return rightTallerWall
    
    def trap(self, height: List[int]) -> int:
        # construct next wall to left arr
        left = self.constructArr(height)
        
        # construct next wall to right arr
        right = self.constructArr2(height)
        
        # calculate answer
        ans = 0
        for i in range(len(left)):
            if left[i] < 0 or right[i] < 0:
                continue
            ans += min(left[i], right[i]) - height[i]
        
        return ans