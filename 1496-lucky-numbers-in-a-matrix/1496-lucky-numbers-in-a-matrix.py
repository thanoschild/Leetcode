class Solution(object):
    def luckyNumbers (self, mat):
        n = len(mat)
        m = len(mat[0])
        min_row = [float('inf')] * n
        max_col = [float('-inf')] * m

        for i in range(n):
            for j in range(m):
                min_row[i] = min(min_row[i], mat[i][j])
                max_col[j] = max(max_col[j], mat[i][j])

        ans = []
        for i in range(n):
            for j in range(m):
                if min_row[i] == max_col[j]:
                    ans.append(min_row[i])
                    break

        return ans
        