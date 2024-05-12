class Solution(object):
    def largestLocal(self, grid):
        n = len(grid)
        ans = [[0 for _ in range(n-2)] for _ in range(n-2)]

        for i in range(n-2):
            for j in range(n-2):
                val = float('-inf')
                for x in range(i, i + 3):
                    for y in range(j, j + 3):
                        val = max(val, grid[x][y])
                ans[i][j] = val
            
        return ans
        