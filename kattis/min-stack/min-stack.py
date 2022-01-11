class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.minE = float('inf')
        self.stk = [] # main stack

    def push(self, val: int) -> None:
        self.minE = min(self.minE, val)
        self.stk.append((val, self.minE))
        
    def pop(self) -> None:
        self.stk.pop()
        if self.stk:
            self.minE = self.stk[-1][1]
        else:
            self.minE = float('inf')
            
    def top(self) -> int:
        return self.stk[-1][0] # (val, minE)

    def getMin(self) -> int:
        return self.stk[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

"""
-20, -20
-7 -20
-7 -20
10 -20
14 -10
-10 -10


0 -2
-2 -2
"""