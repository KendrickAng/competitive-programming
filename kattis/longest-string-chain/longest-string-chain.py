class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        def predecessor(a, b):
            # returns true if a is a predecessor of b
            if len(a) != len(b) - 1:
                return False
            for i in range(len(b)):
                if b[:i] + b[i+1:] == a:
                    return True
            return False
            
        def bfs(adjList, startWord):
            dq = deque([(startWord, 1)])
            maxLen = -1
            seen = set()
            
            while dq:
                word, length = dq.popleft()
                maxLen = max(maxLen, length)
                
                if word not in seen:
                    seen.add(word)
                    for neigh in adjList[word]:
                        dq.append((neigh, length + 1))

            return maxLen
        
        # form the adjlist -> O(N2)
        n = len(words)
        adjList = defaultdict(list)
        for i in range(n):
            for j in range(n):
                if i != j and predecessor(words[i], words[j]):
                    adjList[words[i]].append(words[j])
        
        # bfs for each word
        ans = -1
        for word in words:
            length = bfs(adjList, word)
            ans = max(ans, length)
            
        return ans