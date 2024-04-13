class Solution(object):
    def maximalRectangle(self, mat):
        n = len(mat)
        m = len(mat[0])
        dp = [[0] * m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if i == 0:
                    dp[i][j] = int(mat[i][j])
                else:
                    if mat[i][j] == '0':
                        dp[i][j] = 0
                    else:
                        dp[i][j] = dp[i-1][j] + 1

        ans = 0
        for i in range(n):
            st = []
            for j in range(m+1):
                curr = 0 if j == m else dp[i][j]
                while st and dp[i][st[-1]] > curr:
                    h = dp[i][st.pop()]
                    l = j if not st else j - st[-1] - 1
                    ans = max(ans, l * h)
                st.append(j)

        return ans