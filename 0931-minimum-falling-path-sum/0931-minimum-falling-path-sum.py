class Solution(object):
    def minFallingPathSum(self, mat):
        N = len(mat)
        for i in range(1, N):
            for j in range(N):
                mat[i][j] += min(mat[i - 1][k] for k in (j - 1, j, j + 1) if 0 <= k < N)
        return min(mat[-1])
        