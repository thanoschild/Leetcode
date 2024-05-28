class Solution(object):
    def equalSubstring(self, s, t, maxCost):
        n, i, j = len(s), 0, 0
        while i < n:
            maxCost -= abs(ord(s[i]) - ord(t[i]))
            if maxCost < 0:
                maxCost += abs(ord(s[j]) - ord(t[j]))
                j += 1
            i += 1
        
        return i - j
        