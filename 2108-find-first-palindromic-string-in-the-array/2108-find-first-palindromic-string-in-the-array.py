class Solution(object):
    def check(self, s):
        i, j = 0, len(s) - 1
        while i<=j:
            if s[i] == s[j]:
                i += 1
                j -= 1
            else: return False
        
        return True


    def firstPalindrome(self, words):
        for s in words:
            if self.check(s): return s
            
        return ""
        