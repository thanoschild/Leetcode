class Solution(object):
    def setZeroes(self, matrix):
        n, m = len(matrix), len(matrix[0])
        row, col = 0, 0
        
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    if i == 0:
                        row = 1
                    if j == 0:
                        col = 1
                    matrix[i][0] = 0
                    matrix[0][j] = 0
                
                
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        
        if row == 1:
            for j in range(m):
                matrix[0][j] = 0
                
        if col == 1:
            for i in range(n):
                matrix[i][0] = 0
        