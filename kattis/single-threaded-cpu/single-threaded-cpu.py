class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        def enqTime(task):
            return task[0]
        def processTime(task):
            return task[1]
        def addTask(pq, task):
            # process time, index
            tmp = (processTime(task), task[2])
            heapq.heappush(pq, tmp)
            
        pq = []
        
        tasks = sorted([(task[0], task[1], i) for i, task in enumerate(tasks)])
        idx = 0
        time = 0
        ans = []
        
        while idx < len(tasks):
            if not pq:
                nextTask = tasks[idx]
                addTask(pq, nextTask)
                time = enqTime(nextTask)
                idx += 1
            
            # process the next task at this time
            timeToProcess, taskIdx = heapq.heappop(pq)
            ans.append(taskIdx)
            time += timeToProcess
            
            # enqueue all new available tasks
            while idx < len(tasks) and enqTime(tasks[idx]) <= time:
                addTask(pq, tasks[idx])
                idx += 1
        
        while pq:
            timeToProcess, taskIdx = heapq.heappop(pq)
            ans.append(taskIdx)
        
        return ans
    
"""
1, 2
2, 4
3, 2
4, 1

init pq ordered by process time, index
init map

sort list by increasing enqueue time
idx = 0
time = 0

while idx < len(list):
    if pq is empty:
        binray search next greater time
        idx = next greater index
        time = list[idx].getEnqueenTime
        pq.addall(map[idx])
    
    # process the next task at this time
    task = pq.pop()
    
    # enqueue all new available tasks
    while idx < len(list) and list[idx].getEnqueueTiem < time:
        toadd = map[list[idx].getEngqueuTime]
        pq.addall(toadd) // and add index
        idx += 1

return ans
    
"""