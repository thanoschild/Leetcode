class Solution(object):
    def numSquares(self, n):
        dp = [10**9] * (n+1)
        dp[0], dp[1] = 0, 1

        for i in range(2, n+1):
            j = 1
            while j*j <= i:
                dp[i] = min(dp[i], dp[i-j*j] + 1)
                j += 1
        
        return dp[n]
        