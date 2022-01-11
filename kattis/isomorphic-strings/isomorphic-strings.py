class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        replace = {}
        mapped = set()
        for i in range(len(s)):
            ss = s[i]
            tt = t[i]
            if ss in replace:
                if replace[ss] != tt:
                    return False
            else:
                if tt in mapped:
                    return False
                replace[ss] = tt
                mapped.add(tt)
                
        return True