class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        res = []
        h1 = [[weight, i ,0] for i, weight in enumerate(servers)]
        h2 = []
        heapq.heapify(h1)
        for j, task in enumerate(tasks):
            while h2 and h2[0][0] <= j or not h1:
                time, weight, i = heapq.heappop(h2)
                heapq.heappush(h1, [weight, i, time])
            weight, i, time = heapq.heappop(h1)
            res.append(i)
            heapq.heappush(h2, [max(time,j)+task, weight, i])
        return res
    
"""
servers     3 3 2
tasks       1 2 3 2 1 2

priorty for servers
time, weight

currTime: 1

waiting:
3 3 0

pq:
3 1
2 2
"""