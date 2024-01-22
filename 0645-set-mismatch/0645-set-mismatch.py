class Solution(object):
    def findErrorNums(self, nums):
        ans = [-1]*2
        for x in nums:
            if nums[abs(x) - 1] < 0:
                ans[0] = abs(x)
            else:
                nums[abs(x) - 1] *= -1
            
        for i in range(len(nums)):
            if nums[i] > 0:
                ans[1] = i + 1
        
        return ans
        