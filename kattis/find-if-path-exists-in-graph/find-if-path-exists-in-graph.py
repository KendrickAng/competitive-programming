from collections import defaultdict

class Solution:
    def validPath(self, n: int, edges: List[List[int]], start: int, end: int) -> bool:
        def convert(edges):
            adjlist = defaultdict(list)
            for u, v in edges:
                adjlist[u].append(v)
                adjlist[v].append(u)
            return adjlist
        def dfs(node, al, visited):
            visited[node] = True
            for neighbour in al[node]:
                if not visited[neighbour]:
                    dfs(neighbour, al, visited)
        
        # convert to adjlist
        al = convert(edges)
        
        # dfs once
        visited = [False] * n
        dfs(start, al, visited)
        
        if visited[end]:
            return True
        return False