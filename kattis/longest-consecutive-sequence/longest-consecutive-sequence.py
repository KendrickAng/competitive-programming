from collections import deque

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        adjList = defaultdict(list)
        indegree = defaultdict(int)

        # init
        for num in nums:
            adjList[num] = []
            indegree[num] = 0

        # count indegree
        for num in nums:
            if num+1 in indegree:
                indegree[num+1] += 1
                adjList[num].append(num+1) # connect nodes

        # get all starting nodes (indegree 0)
        start = []
        for key, val in indegree.items():
            if val == 0:
                start.append((key, 1))
        #rint(start)
                
        # bfs
        ans = 0
        dq = deque(start)
        seen = set()
        while dq:
            curr, length = dq.popleft()
            ans = max(ans, length) # kee ptrack of max length of seq
            if curr not in seen:
                seen.add(curr)
                for neigh in adjList[curr]:
                    dq.append((neigh, length + 1))
        return ans
    
"""
100 4 200 1 3 2
1 2 3 4

1 - 2 - 3 - 4
100
200

0 3 7 2 5 8 4 6 0 1
0 1 2 3 4 5 6 7 8 len 9

0 - 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8


make graph
maintain indegree
bfs from all nodes with indegree 0
dont keep track of dups
goes through each node once

adjList = defaultdict(list)
indegree = defaultdict(int)

# init
for num in nums:
    adjList[num] = []
    indegree[num] = 0

# count indegree
for num in nums:
    if num+1 in adjList:
        indegree[num+1] += 1
    
# get all starting nodes (indegree 0)
start = []
for key, val in indegree.items():
    if val == 0:
        start.append((key, 1))
        
# bfs
ans = -1
dq = deque(start)
seen = set()
while dq:
    curr, length = dq.popleft()
    ans = max(ans, length) # kee ptrack of max length of seq
    if curr not in seen:
        seen.add(curr)
        for neigh in adjList[curr]:
            dq.append((neigh, length + 1))
return ans
"""