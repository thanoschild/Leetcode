class Solution(object):
    def maximumImportance(self, n, roads):
        indeg = [0] * n
        for x in roads:
            indeg[x[0]] += 1
            indeg[x[1]] += 1
        
        indeg.sort()
        ans, val = 0, 1
        for x in indeg:
            ans += (val * x)
            val += 1
        
        return ans
        