class Solution(object):
    def findMaxK(self, nums):
        nums.sort()
        i, j = 0, len(nums) - 1

        while i < j and nums[i] < 0 and nums[j] > 0:
            if abs(nums[i]) == nums[j]:
                return nums[j]
            if abs(nums[i]) > nums[j]:
                i += 1
            else:
                j -= 1
            
        return -1
        