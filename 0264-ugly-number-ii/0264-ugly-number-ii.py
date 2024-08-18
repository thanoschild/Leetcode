class Solution(object):
    def nthUglyNumber(self, n):
        k2 = k3 = k5 = 0
        dp = [0] * (n + 1)
        dp[0] = 1

        for i in range(1, n + 1):
            dp[i] = min(2*dp[k2], 3*dp[k3], 5*dp[k5])
            if dp[i] == 2*dp[k2]:
                k2 += 1
            if dp[i] == 3*dp[k3]:
                k3 += 1
            if dp[i] == 5*dp[k5]:
                k5 += 1
        
        return dp[n-1]