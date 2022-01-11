class Solution:
    def willCollide(self, a, b):
        return a > 0 and b < 0
    
    def collide(self, a, b):
        if abs(a) == abs(b):
            return None
        elif abs(a) > abs(b):
            return a
        else:
            return b
    
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        # create a stack
        stk = []
        
        # go through the input array
        # stack invariant: does not contain colliding asteroids
        for ast in asteroids:
            if not stk:
                stk.append(ast)
            else:
                while stk and self.willCollide(stk[-1], ast):
                    toCollide = stk.pop()
                    ast = self.collide(toCollide, ast)
                    if not ast:
                        break
                if ast:
                    stk.append(ast)
        
        return stk