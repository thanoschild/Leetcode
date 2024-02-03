class Solution(object):
    def solve(self, idx, arr, k, dp):
        if idx == len(arr): return 0
        if dp[idx] != -1: return dp[idx]

        _len, maxval, maxans = 0, 0, 0
        for i in range(idx, min(idx + k, len(arr))):
            _len += 1
            maxval = max(maxval, arr[i])
            sum = _len*maxval + self.solve(i+1, arr, k, dp)
            maxans = max(maxans, sum)
        
        dp[idx] = maxans
        return dp[idx]
        
    def maxSumAfterPartitioning(self, arr, k):
        n = len(arr)
        dp = [-1] * n
        return self.solve(0, arr, k, dp)
        