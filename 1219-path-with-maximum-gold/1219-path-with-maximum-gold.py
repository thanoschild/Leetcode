class Solution(object):
    def __init__(self):
        self.dir = [-1, 0, 1, 0, -1]

    def dfs(self, grid, i, j, n, m):
        if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == 0:
            return 0
        original_val = grid[i][j]
        grid[i][j] = 0
        
        max_gold = 0
        for k in range(4):
            x = i + self.dir[k]
            y = j + self.dir[k + 1]
            max_gold = max(max_gold, self.dfs(grid, x, y, n, m))
        
        grid[i][j] = original_val
        return max_gold + original_val

    def getMaximumGold(self, grid):
        n, m = len(grid), len(grid[0])

        ans = 0
        for i in range(n):
            for j in range(m):
                ans = max(ans, self.dfs(grid, i, j, n, m))
        
        return ans
