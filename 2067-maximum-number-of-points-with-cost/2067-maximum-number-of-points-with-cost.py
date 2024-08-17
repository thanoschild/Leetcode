class Solution(object):
    def maxPoints(self, arr):
        n = len(arr)
        m = len(arr[0])
        dp = [[0] * m for _ in range(n)]

        for j in range(m):
            dp[0][j] = arr[0][j]

        for i in range(1, n):
            left_dp = [0] * m
            right_dp = [0] * m

            left_dp[0] = dp[i-1][0]  
            for j in range(1, m):
                left_dp[j] = max(left_dp[j-1], dp[i-1][j] + j)

            right_dp[m-1] = dp[i-1][m-1] - (m - 1) 
            for j in range(m - 2, -1, -1):
                right_dp[j] = max(right_dp[j+1], dp[i-1][j] - j)

            for j in range(m):
                dp[i][j] = max(left_dp[j] - j, right_dp[j] + j) + arr[i][j]

        return max(dp[-1])
        