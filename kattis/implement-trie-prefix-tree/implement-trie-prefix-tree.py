from collections import defaultdict

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        self.root.insert(word)

    def search(self, word: str) -> bool:
        return self.root.search(word)

    def startsWith(self, prefix: str) -> bool:
        return self.root.startsWith(prefix)
        
class TrieNode:
    def __init__(self):
        self.mappings = defaultdict(TrieNode)   # letter -> trienode
        self.isEnd = False                      # do I form a word?
        
    def insert(self, word):
        if not self.search(word):
            node = self
            for letter in word:
                nextN = node.mappings[letter]
                node = nextN
            node.isEnd = True
        
    def search(self, word):
        node = self
        for letter in word:
            if letter not in node.mappings:
                return False
            else:
                node = node.mappings[letter]
        return True if node.isEnd else False
    
    def startsWith(self, prefix):
        node = self
        for letter in prefix:
            if letter not in node.mappings:
                return False
            else:
                node = node.mappings[letter]
        return True
    

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)