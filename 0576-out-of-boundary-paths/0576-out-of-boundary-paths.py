class Solution(object):
    def solve(self, n, m, move, i, j, dp):
        if i < 0 or i == n or j < 0 or j == m: return 1
        if move == 0: return 0
        if dp[i][j][move] != -1: return dp[i][j][move]

        count = 0
        dir = [-1, 0, 1, 0, -1]
        for k in range(4):
            x = i + dir[k]
            y = j + dir[k+1]
            count = (count + self.solve(n, m, move-1, x, y, dp)) % (10**9 + 7)
        
        dp[i][j][move] = count
        return dp[i][j][move]

    def findPaths(self, m, n, maxMove, startRow, startColumn):
        dp = [[[-1 for _ in range(maxMove + 1)] for _ in range(n+1)] for _ in range(m + 1)]
        return self.solve(m, n, maxMove, startRow, startColumn, dp)

        