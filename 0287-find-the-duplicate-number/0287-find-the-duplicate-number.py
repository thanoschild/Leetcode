class Solution(object):
    def findDuplicate(self, nums):
        for i in range(0, len(nums)):
            idx = abs(nums[i]) - 1
            nums[idx] *= -1
            if nums[idx] > 0:
                return abs(nums[i])
            
        return -1
        