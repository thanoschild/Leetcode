class Solution(object):
    def missingNumber(self, nums):
        i, ans = 0, 0
        while i < len(nums):
            ans = (ans ^ i ^ nums[i])
            i += 1
        ans = ans ^ i
        return ans
        