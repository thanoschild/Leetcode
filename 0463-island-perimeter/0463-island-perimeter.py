class Solution(object):
    def islandPerimeter(self, grid):
        n, m, ans = len(grid), len(grid[0]), 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    ans += 4
                    if i > 0 and grid[i-1][j] == 1:
                        ans -= 2
                    if j > 0 and grid[i][j-1] == 1:
                        ans -= 2
        
        return ans

