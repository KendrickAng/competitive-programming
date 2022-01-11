class Solution:
    def simplifyPath(self, path: str) -> str:
        stk = []
        tokens = path.split('/')
        for token in tokens:
            if not token: continue
            elif token == ".":
                continue
            elif token == "..":
                if stk: stk.pop()
            else:
                stk.append(token)
        return "/" + "/".join(stk)
        
# /home/ -> /home
# /../ -> /
# /home//foo/ -> /home/foo
# /a/./b/../../c/ -> /c