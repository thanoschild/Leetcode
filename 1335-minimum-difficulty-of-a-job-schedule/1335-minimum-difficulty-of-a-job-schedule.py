class Solution(object):
    def minDifficulty(self, jobDifficulty, d):
        n = len(jobDifficulty)
        if n < d:
            return -1

        dp = [[-1] * (d + 1) for _ in range(n + 1)]

        def solve(idx, days):
            if idx == n and days == 0:
                return 0
            if idx == n or days == 0 or n - idx < days:
                return 1000009
            if dp[idx][days] != -1:
                return dp[idx][days]

            ans, maxele = 1000009, float('-inf')
            for i in range(idx, n):
                maxele = max(maxele, jobDifficulty[i])
                ans = min(ans, maxele + solve(i + 1, days - 1))

            dp[idx][days] = ans
            return dp[idx][days]

        return solve(0, d)
        