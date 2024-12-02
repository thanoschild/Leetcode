class Solution(object):
    def isPrefixOfWord(self, sentence, searchWord):
        words = sentence.split(" ")
        for i, word in enumerate(words):
            if word.startswith(searchWord):
                return i + 1

        return -1
        