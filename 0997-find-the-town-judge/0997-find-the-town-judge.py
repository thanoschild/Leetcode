class Solution(object):
    def findJudge(self, n, trust):
        indeg = [0] * (n+1)
        for it in trust:
            indeg[it[0]] -= 1
            indeg[it[1]] += 1
        
        for i in range(1, n+1):
            if indeg[i] == n - 1:
                return i
            
        return -1

        