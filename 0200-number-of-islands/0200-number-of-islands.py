class Solution(object):
    def dfs(self, grid, i, j, n, m):
        if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == '0':
            return
        
        grid[i][j] = '0'
        dir = [-1, 0, 1, 0, -1]
        for k in range(4):
            x, y = dir[k] + i, dir[k+1] + j
            self.dfs(grid, x, y, n, m)

    def numIslands(self, grid):
        n, m, ans = len(grid), len(grid[0]), 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j, n, m)
                    ans += 1
        
        return ans

        