class Solution(object):
    def minFallingPathSum(self, grid):
        n = len(grid)
        dp = grid[n - 1]

        for i in range(n - 2, -1, -1):
            first_min, second_min, idx = float('inf'), float('inf'), -1
            for j in range(n):
                if first_min > dp[j]:
                    second_min = first_min
                    first_min = dp[j]
                    idx = j
                elif second_min > dp[j]:
                    second_min = dp[j]
            
            for j in range(n):
                if j == idx:
                    dp[j] = grid[i][j] + second_min
                else:
                    dp[j] = grid[i][j] + first_min
            
        return min(dp)
        