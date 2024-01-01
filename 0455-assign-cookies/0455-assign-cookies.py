class Solution(object):
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()

        count, i, j = 0, 0, 0
        while i < len(g) and j < len(s):
            if g[i] <= s[j]:
                count += 1
                i += 1
                j += 1
                continue
            j += 1

        return count
        