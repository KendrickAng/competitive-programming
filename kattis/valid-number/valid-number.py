class Solution:
    """
    -123.456e789
                    
    """
    def isNumber(self, s: str) -> bool:
        cursor = 0
        
        def saveCursor():
            nonlocal cursor
            return cursor
        
        def backtrack(c):
            nonlocal cursor
            cursor = c
        
        def isValid():
            nonlocal cursor, s
            return cursor == len(s)
        
        def dot():
            nonlocal cursor, s
            if cursor >= len(s): return
            parsed = False
            if s[cursor] == ".":
                cursor += 1
                parsed = True
            return parsed
        
        def eE():
            nonlocal cursor, s
            if cursor >= len(s): return
            parsed = False
            if s[cursor] in ("e", "E"):
                cursor += 1
                parsed = True
            return parsed

        def digits(): # compulsory
            nonlocal cursor, s
            if cursor >= len(s): return False
            parsed = False
            while cursor < len(s) and s[cursor].isdigit():
                cursor += 1
                parsed = True
            return parsed
        
        def decimal():
            nonlocal cursor, s
            if cursor >= len(s): return False
            if s[cursor] in ("+", "-"): cursor += 1 # eat + or -
            c = saveCursor()
            if digits() and dot() and digits(): return True
            backtrack(c)

            c = saveCursor()
            if digits() and dot(): return True
            backtrack(c)

            c = saveCursor()
            if dot() and digits(): return True
            backtrack(c)

            return False
        
        def integer():
            nonlocal cursor, s
            if cursor >= len(s): return False
            if s[cursor] in ("+", "-"): cursor += 1 # eat + or -
            
            c = saveCursor()
            if digits(): return True
            backtrack(c)
            
            return False
        
        # try decimal
        c = saveCursor()
        if decimal() and isValid(): 
            # print("a")
            return True
        backtrack(c)
        
        c = saveCursor()
        if decimal() and eE() and integer() and isValid(): 
            # print("b")
            return True
        backtrack(c)
        
        c = saveCursor()
        if integer() and isValid(): return True
        backtrack(c)
        
        c = saveCursor()
        if integer() and eE() and integer() and isValid():
            #print("d")
            return True
        backtrack(c)
        
        return False
    
"""
2
0089
-0.1
+3.14
4.

cursor
savecursor()
backtrack() # restores the cursor

save cursor
try stuff
backtrack if fail

valid number = parseDecimal() or parseInteger() or parseDecimal() w/ parseE/e w/ parseInteger()
valid decimal = optional sign w/ case1() or case2() or case3()
valid integer = optional sign w/ digits
"""