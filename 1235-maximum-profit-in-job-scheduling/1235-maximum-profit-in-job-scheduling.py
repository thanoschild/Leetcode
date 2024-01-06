class Solution(object):
    def jobScheduling(self, start, end, pro):
        jobs = sorted(zip(start, end, pro), key=lambda v: v[1])
        dp = [[0, 0]]

        for s, e, p in jobs:
            i = bisect.bisect(dp, [s + 1]) - 1
            if dp[i][1] + p > dp[-1][1]:
                dp.append([e, dp[i][1] + p])
            
        return dp[-1][1]
        