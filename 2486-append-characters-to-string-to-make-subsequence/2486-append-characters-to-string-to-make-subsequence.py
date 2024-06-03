class Solution(object):
    def appendCharacters(self, s, t):
        i, j, n, m = 0, 0, len(s), len(t)
        while i < n and j < m:
            if s[i] == t[j]:
                i += 1
                j += 1
            else:
                i += 1
        
        return m - j
        