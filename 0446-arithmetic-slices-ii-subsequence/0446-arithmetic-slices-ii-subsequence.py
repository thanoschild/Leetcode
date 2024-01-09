class Solution(object):
    def numberOfArithmeticSlices(self, nums):
        n = len(nums)
        dp = [defaultdict(int) for _ in range(n)]
        ans = 0

        for i in range(1, n):
            for j in range(i):
                diff = nums[i] - nums[j]
                count = dp[j][diff] if diff in dp[j] else 0
                dp[i][diff] += count + 1
                ans += count

        return ans
        