class Solution(object):
    def __init__(self):
        self.dp = [[-1] * 127 for _ in range(127)]
    
    def find(self, x):
        return 0 if x == 1 else 1 if x < 10 else 2 if x < 100 else 3

    def solve(self, s, start, k, n):
        if k < 0: return 127
        if start >= n or n - start <= k: return 0
        if self.dp[start][k] != -1: return self.dp[start][k]

        ans = 127
        most = 0
        count = [0]*26
        for i in range(start, n):
            count[ord(s[i]) - ord('a')] += 1
            most = max(most, count[ord(s[i]) - ord('a')])
            ans = min(ans, 1 + self.find(most) + self.solve(s, i + 1, k - (i - start + 1 - most), n))
        self.dp[start][k] = ans

        return ans

    def getLengthOfOptimalCompression(self, s, k):
        self.dp = [[-1] * 127 for _ in range(127)]
        return self.solve(s, 0, k, len(s))
        
        