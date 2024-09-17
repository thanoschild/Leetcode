class Solution(object):
    def uncommonFromSentences(self, s1, s2):
        words = (s1 + " " + s2).split()
        word_count = Counter(words)
        return [word for word, count in word_count.items() if count == 1]
        