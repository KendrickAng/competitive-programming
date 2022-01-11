from collections import defaultdict

class Solution:
    UNEXPLORED = -1
    EXPLORING = -2
    EXPLORED = -3
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # create adjList
        adjList = defaultdict(list)
        for a, b in prerequisites:
            # if a == b:
            #     return False
            adjList[b].append(a)
                            
        # detect cycle
        explored = [Solution.UNEXPLORED for i in range(numCourses)]
        for start in range(numCourses):
            if explored[start] == Solution.UNEXPLORED:
                if self.hasCycle(start, adjList, explored):
                    return False
        return True
    
    def hasCycle(self, node, adjList, explored):
        explored[node] = Solution.EXPLORING
        cycle = False
        
        for neigh in adjList[node]:
            status = explored[neigh]
            if status == Solution.UNEXPLORED:
                cycle = cycle or self.hasCycle(neigh, adjList, explored)
            elif status == Solution.EXPLORING:
                print(node, neigh)
                return True
            elif status == Solution.EXPLORED:
                # do nothing
                pass
            
        explored[node] = Solution.EXPLORED
        return cycle