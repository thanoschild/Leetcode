class Solution(object):
    def longestIdealString(self, s, k):
        dp = [0] * 26
        ans = 0

        for c in s:
            i = ord(c) - ord('a')
            dp[i] += 1
            for j in range(max(0, i - k), min(25, i + k) + 1):
                if i != j:
                    dp[i] = max(dp[i], dp[j] + 1)
            ans = max(ans, dp[i])

        return ans        