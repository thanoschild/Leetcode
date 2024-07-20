class Solution(object):
    def restoreMatrix(self, row, col):
        n, m = len(row), len(col)
        ans = [[0] * m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                ans[i][j] = min(col[j], row[i])
                row[i] -= ans[i][j]
                col[j] -= ans[i][j]
            
        return ans