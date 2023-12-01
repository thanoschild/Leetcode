class Solution(object):
    def arrayStringsAreEqual(self, word1, word2):
        s1, s2 = "", ""
        
        for x in word1:
            s1 += x
        for x in word2:
            s2 += x
            
        return s1 == s2
        