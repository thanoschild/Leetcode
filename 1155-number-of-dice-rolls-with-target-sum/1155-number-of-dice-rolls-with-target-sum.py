class Solution(object):
    def solve(self, n, k, target, dp):
        if n == 0 and target == 0: return 1
        if n < 0 or target < 0: return 0
        if (n, target) in dp: return dp[(n, target)]

        sum = 0
        for i in range(1, k+1):
            sum = (sum + self.solve(n-1, k, target - i, dp))%(10**9 + 7)
        dp[(n, target)] = sum

        return dp[(n, target)]

    def numRollsToTarget(self, n, k, target):
        dp = {}
        return self.solve(n, k, target, dp)
        