class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, k):
        dp = [[float('inf')] * n for _ in range(k+2)]
        for i in range(0, k+2):
            dp[i][src] = 0

        for i in range(1, k+2):
            for u, v, w in flights:
                if dp[i-1][u] != float('inf'):
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + w)

        
        return -1 if dp[k+1][dst] == float('inf') else dp[k+1][dst]