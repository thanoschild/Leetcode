class Solution(object):
    def makeEqual(self, words):
        n = len(words)
        freq = [0] * 26

        for word in words:
            for c in word:
                freq[ord(c) - ord('a')] += 1
            
        for i in range(26):
            if freq[i] % n != 0:
                return False

        return True
        