class Solution(object):
    def minDifference(self, nums):
        n = len(nums)
        if n < 5:
            return 0
        nums.sort()
        a = nums[n-1] - nums[3]
        b = nums[n-2] - nums[2]
        c = nums[n-3] - nums[1]
        d = nums[n-4] - nums[0]

        return min(a, min(b, min(c, d)))
        