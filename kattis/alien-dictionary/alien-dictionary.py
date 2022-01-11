from collections import Counter, defaultdict, deque

class Solution:
    def alienOrder(self, words: List[str]) -> str:
        adjList = defaultdict(set)
        indegree = Counter({ c:0 for word in words for c in word })
        
        for first, second in zip(words, words[1:]):
            if len(second) < len(first) and first.startswith(second):
                return ""
            for a, b in zip(first, second):
                if a != b:
                    if b not in adjList[a]:
                        adjList[a].add(b)
                        indegree[b] += 1
                    break

        ret = []
        q = deque([c for c in indegree if indegree[c] == 0])
        while q:
            c = q.popleft()
            ret.append(c)
            for neigh in adjList[c]:
                indegree[neigh] -= 1
                if indegree[neigh] == 0:
                    q.append(neigh)
                    
                    
        if len(ret) < len(indegree):
            return ""
        return "".join(ret)