class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0

        def differOne(word1, word2):
            if len(word1) != len(word2):
                return False
            differs = 0
            for i in range(len(word1)):
                if word1[i] != word2[i]:
                    differs += 1
            return differs == 1
                    
        # start from beginword
        # by doing this, can exclude beginword from the adjlist
        dq = deque([(beginWord, 1)])
        wordList = set(wordList)
   
        # bfs
        while dq:
            word, pathLen = dq.popleft()

            # end state
            if word == endWord:
                return pathLen

            for i in range(len(word)):
                for c in string.ascii_lowercase:
                    next_word = word[:i] + c + word[i+1:]
                    if next_word in wordList:
                        wordList.discard(next_word)
                        dq.append((next_word, pathLen + 1))

        # cannot find answer
        return 0 
"""
bfs
generate adjList from wordlist
every word has a entry, neighbours = words that differ by single letter
bfs from beginword
if works, output the path length
otherwise, output 0
N^2

if beginWord not in wordList:
    return 0

adjList = defaultdict(list)

# generate adjlist
n = len(wordList)
for i in range(n):
    for j in range(i+1, n):
        word1 = wordList[i]
        word2 = wordList[j]
        if differLetters(word1, word2) == 1:
            adjList[word1].append(word2)
            adjList[word2].append(word1)

# start from beginword
# by doing this, can exclude beginword from the adjlist
dq = deque()
for word in wordList:
    if differLetters(beginWord, word) == 1:
        dq.append((word, 1))
        
# bfs
seen = set()
while dq:
    word, pathLen = dq.popleft()
    
    # end state
    if word == endWord:
        return pathLen
    
    if word not in seen:
        seen.add(word)
        for neighbour in adjList[word]:
            dq.append(neighbour, pathLen + 1)

# cannot find answer
return -1
"""