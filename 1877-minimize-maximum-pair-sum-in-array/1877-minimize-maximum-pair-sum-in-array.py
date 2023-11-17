class Solution(object):
    def minPairSum(self, nums):
        nums.sort()
        ans1, ans2, n = -10**9, -10**9, len(nums)
        for i in range(n//2):
            ans1 = max(ans1, nums[i] + nums[n-1-i])
            ans2 = max(ans2, nums[i] + nums[n/2 + i])
        
        return min(ans1, ans2)
        