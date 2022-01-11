from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def sortLexi(s): # s = string
            return "".join(sorted(list(s)))
            
        d = defaultdict(list)
        for string in strs:
            key = sortLexi(string)
            d[key].append(string)
        return list(d.values())
    
"""
eat tea tan ate nat bat
eat tea ate - key: aet
bat         - key: abt
nat tan     - key: ant

O(N * slogs)
"""