class Solution(object):
    def prefixCount(self, words, pref):
        ans, n = 0, len(pref)
        for word in words:
            if word[0:n] == pref:
                ans += 1
        
        return ans
        