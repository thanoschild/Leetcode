class Solution(object):
    def findRotateSteps(self, ring, key):
        n, m = len(ring), len(key)
        dp = [[0 for _ in range(n)] for _ in range(m+1)]

        for i in range(m-1, -1, -1):
            for j in range(n):
                dp[i][j] = float('inf')
                for k in range(n):
                    if ring[k] == key[i]:
                        diff = abs(j - k)
                        step = min(diff, n - diff)
                        dp[i][j] = min(dp[i][j], step + dp[i+1][k])

        return dp[0][0] + m 
        