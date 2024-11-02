class Solution(object):
    def isCircularSentence(self, s):
        if s[0] != s[-1]:
            return False
        
        for i in range(1, len(s)):
            if s[i] == ' ' and s[i-1] != s[i+1]:
                return False
        
        return True
        