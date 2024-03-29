class Solution(object):
    def firstUniqChar(self, s):
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord('a')] += 1
        
        for i in range(len(s)):
            if freq[ord(s[i]) - ord('a')] == 1: return i
        
        return -1
        