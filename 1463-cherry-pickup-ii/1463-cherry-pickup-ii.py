class Solution(object):
    def __init__(self):
        self.dir = [-1, 0, 1]
        self.dp = None


    def solve(self, grid, i, j1, j2, n, m):
        if i == n:
            return 0
        if j1 < 0 or j2 < 0 or j1 > m - 1 or j2 > m - 1:
            return float('-inf')
        if self.dp[i][j1][j2] != -1:
            return self.dp[i][j1][j2]

        ans = 0
        for k in range(3):
            for l in range(3):
                ans = max(ans, self.solve(grid, i + 1, j1 + self.dir[k], j2 + self.dir[l], n, m))
        ans += grid[i][j1] if j1 == j2 else grid[i][j1] + grid[i][j2]
        self.dp[i][j1][j2] = ans
        return ans


    def cherryPickup(self, grid):
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        self.dp = [[[-1] * m for _ in range(m)] for _ in range(n)]
        return self.solve(grid, 0, 0, m - 1, n, m)

        