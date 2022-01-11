class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        current = self.root
        for letter in word:
            current = current.children[letter]
        current.isWord = True

    def search(self, word: str) -> bool:
        hasMatch = False
        # searches for a single word
        def helper(current, word, currIdx):
            nonlocal hasMatch
            for i in range(currIdx, len(word)):
                letter = word[i]
                
                # dfs if get accept-all node
                if letter == ".":
                    for tn in current.children.values():
                        helper(tn, word, i+1)
                    return
                        
                elif letter not in current.children:
                    # otherwise, continue checking the letters in order
                    return
                
                current = current.children[letter]
                
            hasMatch |= current.isWord
        
        helper(self.root, word, 0)
        return hasMatch
        
class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.isWord = False

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)