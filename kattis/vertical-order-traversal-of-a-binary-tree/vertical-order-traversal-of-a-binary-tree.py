# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return None
        
        # graph nodes, col -> row -> list
        graph = defaultdict(lambda: defaultdict(list))
        
        # fill map of col -> 
        dq = deque([(0,0,root)])
        minCol = float('inf')
        maxCol = float('-inf')
        while dq:
            r, c, node = dq.popleft()
            graph[c][r].append(node.val)
            
            minCol = min(minCol, c)
            maxCol = max(maxCol, c)
            
            # add neighborus
            if node.left:
                dq.append((r+1,c-1,node.left))
            if node.right:
                dq.append((r+1,c+1,node.right))
        #print(graph)
        # modified bfs
        ans = []
        for col in range(minCol, maxCol+1):
            tmp = []
            rows = list(graph[col].keys())
            rows.sort() # top-to-bottom
            for row in rows:
                valList = graph[col][row]
                if len(valList) > 1:
                    tmp.extend(sorted(valList)) # sort by values
                else:
                    tmp.extend(valList)
            ans.append(tmp)
                    
        return ans
    
"""
        3
    9       20
        15      7
9 3,15 20 7

do a bfs
create map of col -> [elements in that col, ordered]

do modieifeid bfs
start at min col
move right until no more cols
"""