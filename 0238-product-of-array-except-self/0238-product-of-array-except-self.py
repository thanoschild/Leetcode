class Solution(object):
    def productExceptSelf(self, nums):
        n = len(nums)
        ans = [1] * n

        curr = 1
        for i in range(n):
            ans[i] *= curr
            curr *= nums[i]
        
        curr = 1
        for i in range(n-1, -1, -1):
            ans[i] *= curr
            curr *= nums[i]
        
        return ans