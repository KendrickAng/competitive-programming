class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adjlist = defaultdict(list)
        for u, v in edges: # build adjlist
            adjlist[u].append(v)
            adjlist[v].append(u)

        seen = [False] * n

        def dfs(node):
            seen[node] = True
            for neigh in adjlist[node]:
                if not seen[neigh]:
                    dfs(neigh)

        ans = 0
        for node in range(n):
            if not seen[node]:
                print(node)
                dfs(node)
                ans += 1

        return ans    
"""
form adjlist
dfs from each node
maintain seen nodes
return number of times started a new dfs
O(edges + nodes)

adjlist = defaultdict(list)
for u, v in edges: # build adjlist
    adjlist[u].append(v)
    adjlist[v].append(u)
    
seen = [False] * n

def dfs(node):
    seen[node] = True
    for neigh in adjlist[node]:
        if not seen[neigh]:
            dfs(neigh)

ans = 0
for node in range(n):
    if not seen[node]:
        dfs(node)
        ans += 1
        
return ans
"""