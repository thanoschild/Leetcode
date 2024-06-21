class Solution(object):
    def lengthOfLongestSubstring(self, s):
        n = len(s)
        if n == 1:
            return 1

        freq = [-1] * 256
        start = -1
        count = 0

        for i in range(n):
            if freq[ord(s[i])] > start:
                start = freq[ord(s[i])]
            
            freq[ord(s[i])] = i
            count = max(count, i - start)
        
        return count
        