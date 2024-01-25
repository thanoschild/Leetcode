class Solution(object):
    def lcs(self, s1, s2, i, j, dp):
        if i == 0 or j == 0: return 0
        if dp[i][j] != -1: return dp[i][j]

        if s1[i-1] == s2[j-1]:
            dp[i][j] = 1 + self.lcs(s1, s2, i-1, j-1, dp)
            return dp[i][j]
        else:
            dp[i][j] = max(self.lcs(s1, s2, i-1, j, dp), self.lcs(s1, s2, i, j-1, dp))
            return dp[i][j]

    def longestCommonSubsequence(self, s1, s2):
        n, m = len(s1), len(s2)
        dp = [[-1 for _ in range(m+1)] for _ in range(n+1)]
        return self.lcs(s1, s2, n, m, dp)
        