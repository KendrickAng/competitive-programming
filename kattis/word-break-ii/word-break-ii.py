class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:

        # backtrack 1
        """
        def backtrack(res, sol, s, wordDict, index):
            if index == len(s):
                res.append(" ".join(sol))
                return

            for w in wordDict:
                if s.startswith(w, index):
                    sol.append(w)
                    backtrack(res, sol, s, wordDict, index + len(w))
                    sol.pop()
        res = []
        backtrack(res, [], s, wordDict, 0)
        return res
        """

        # backtrack 2
        def backtrack(res, sol, s, wordDict):
            if len(s) == 0:
                res.append(" ".join(sol))
                return

            for w in wordDict:
                if s.startswith(w):
                    sol.append(w)
                    backtrack(res, sol, s[len(w):], wordDict)
                    sol.pop()
        res = []
        backtrack(res, [], s, wordDict)
        return res