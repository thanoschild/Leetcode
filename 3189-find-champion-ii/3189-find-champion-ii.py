class Solution(object):
    def findChampion(self, n, edges):
        indegree = [0] * n
        for e in edges:
            indegree[e[1]] += 1
        
        ans = []
        for i in range(n):
            if indegree[i] == 0:
                ans.append(i)

        return ans[0] if len(ans) == 1 else -1 
        