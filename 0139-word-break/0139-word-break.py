class Solution(object):
    def get_max_len(self, _dict):
        _len = 0
        for s in _dict:
            _len = max(_len, len(s))
        return _len


    def wordBreak(self, s, _dict):
        n, m = len(s), len(_dict)
        if m == 0:
            return False
        max_len = self.get_max_len(_dict)
        st = set(_dict)
        dp = [False] * (n+1)
        dp[0] = True

        for i in range(1, n+1):
            j = i - 1
            while j >= 0 and j - i < max_len:
                if dp[j]:
                    if s[j:i] in st:
                        dp[i] = True
                j -= 1
            
        return dp[n]

        