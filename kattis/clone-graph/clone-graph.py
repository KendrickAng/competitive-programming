"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    
    def __init__(self):
        self.visited = {}
    
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node: return node
        
        if node.val in self.visited:
            return self.visited[node.val]
        
        self_clone = Node(node.val)
        self.visited[node.val] = self_clone
        for neighbor in node.neighbors:
            neigh_clone = self.cloneGraph(neighbor)
            self_clone.neighbors.append(neigh_clone)
        
        return self_clone