class Solution(object):
    def dfs(self, grid, i, j, n, m, curr):
        if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == 0:
            return
        
        grid[i][j] = 0
        curr[2] = max(i, curr[2])
        curr[3] = max(j, curr[3])
        dir = [-1, 0, 1, 0, -1]

        for k in range(4):
            x, y = dir[k] + i, dir[k+1] + j
            self.dfs(grid, x, y, n, m, curr)
  
    def findFarmland(self, grid):
        ans = []
        n, m = len(grid), len(grid[0])

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    curr = [0] * 4
                    curr[0] = curr[2] = i
                    curr[1] = curr[3] = j
                    self.dfs(grid, i, j, n, m, curr)
                    ans.append(curr)
        
        return ans
        