class Solution(object):
    def checkGrid(self, i, j, grid):
        counts = [0] * 10  

        for k in range(i, i + 3):
            sumRows = 0
            for l in range(j, j + 3):
                sumRows += grid[k][l]
                if grid[k][l] < 1 or grid[k][l] > 9:
                    return False
                counts[grid[k][l]] += 1
            if sumRows != 15:
                return False

        for k in range(j, j + 3):
            sumCols = 0
            for l in range(i, i + 3):
                sumCols += grid[l][k]
            if sumCols != 15:
                return False

        leftd = 0
        rightd = 0
        for k in range(3):
            leftd += grid[i + k][j + k]
            rightd += grid[i + k][j + 2 - k]

        if leftd != 15 or rightd != 15:
            return False

        for k in range(1, 10):
            if counts[k] != 1:
                return False

        return True

    def numMagicSquaresInside(self, grid):
        n = len(grid)
        m = len(grid[0])
        if n < 3 or m < 3:
            return 0
        ans = 0

        for i in range(n - 2):
            for j in range(m - 2):
                if self.checkGrid(i, j, grid):
                    ans += 1

        return ans
        