class Solution(object):
    def largestDivisibleSubset(self, nums):
        n = len(nums)
        if n == 1: return nums
        dp = [1]*n
        parent = [0]*n

        source, mx = 0, 1
        nums.sort()
        for i in range(1, n):
            for j in range(0, i):
                if nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    parent[i] = j

            if dp[i] > mx:
                mx = dp[i]
                source = i
            
        ans = []
        for i in range(mx):
            ans.append(nums[source])
            source = parent[source]
        
        return ans

        