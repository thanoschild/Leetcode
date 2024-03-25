class Solution(object):
    def findDuplicates(self, nums):
        ans = []
        for i in range(len(nums)):
            idx = abs(nums[i]) - 1
            nums[idx] *= -1
            if nums[idx] > 0:
                ans.append(abs(nums[i]))
        
        return ans
        