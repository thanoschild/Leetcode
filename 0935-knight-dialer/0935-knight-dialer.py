class Solution(object):
    def __init__(self):
        self.mod = 10**9 + 7

    def find_path(self, i, j, n, dp):
        if i < 0 or j < 0 or i >= 4 or j >= 3 or (i == 3 and j != 1):
            return 0
        if n == 1:
            return 1
        if dp[i][j][n] != -1:
            return dp[i][j][n]

        dp[i][j][n] = (
            self.find_path(i - 1, j - 2, n - 1, dp) % self.mod +
            self.find_path(i - 1, j + 2, n - 1, dp) % self.mod +
            self.find_path(i + 1, j - 2, n - 1, dp) % self.mod +
            self.find_path(i + 1, j + 2, n - 1, dp) % self.mod +
            self.find_path(i - 2, j - 1, n - 1, dp) % self.mod +
            self.find_path(i - 2, j + 1, n - 1, dp) % self.mod +
            self.find_path(i + 2, j - 1, n - 1, dp) % self.mod +
            self.find_path(i + 2, j + 1, n - 1, dp) % self.mod
        ) % self.mod

        return dp[i][j][n]
    
    def knightDialer(self, n):
        ans = 0
        dp = [[[ -1 for _ in range(n + 1)] for _ in range(3)] for _ in range(4)]

        for i in range(4):
            for j in range(3):
                ans = (ans + self.find_path(i, j, n, dp)) % self.mod

        return int(ans)
        