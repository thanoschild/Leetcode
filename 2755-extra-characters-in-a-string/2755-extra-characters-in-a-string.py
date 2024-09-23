class Solution(object):
    def dfs(self, s, dp, st, idx):
        if idx >= len(s):
            return 0
        if dp[idx] != -1:
            return dp[idx]
        
        minlen, _str = len(s), ""
        for i in range(idx, len(s)):
            _str += s[i]
            count = 0 if _str in st else len(_str)
            new_count = self.dfs(s, dp, st, i + 1)
            minlen = min(minlen, count + new_count)
        
        dp[idx] = minlen
        return dp[idx]

    def minExtraChar(self, s, dictionary):
        dp = [-1] * len(s)
        st = set(dictionary)
        return self.dfs(s, dp, st, 0)
        