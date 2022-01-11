from collections import defaultdict
from operator import itemgetter

class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        idToScores = defaultdict(list)
        for sID, score in items:
            idToScores[sID].append(score)
        
        ans = []
        for k, v in idToScores.items():
            v.sort(reverse=True)
            ans.append([k, sum(v[:5]) // 5])
            
        return sorted(ans)
            