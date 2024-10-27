class Solution(object):
    def countSquares(self, matrix):
        n, m, ans = len(matrix), len(matrix[0]), 0
        for i in range(n):
            for j in range(m):
                if i != 0 and j != 0 and matrix[i][j] != 0:
                    matrix[i][j] = min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]) + 1
                ans += matrix[i][j]
        
        return ans
        