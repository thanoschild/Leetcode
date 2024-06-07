class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for c in word:
            index = ord(c) - ord('a')
            if not node.children[index]:
                node.children[index] = TrieNode()
            node = node.children[index]
        node.isEnd = True

    def search(self, word):
        node = self.root
        curr = ""
        for c in word:
            index = ord(c) - ord('a')
            curr += c
            if not node.children[index]:
                return word
            if node.children[index].isEnd:
                return curr
            node = node.children[index]
        return word

class Solution(object):
    def replaceWords(self, dictionary, sentence):
        trie = Trie()
        for word in dictionary:
            trie.insert(word)
        
        result = []
        for word in sentence.split():
            result.append(trie.search(word))
        
        return ' '.join(result)
        