class Solution(object):
    def maxSubArray(self, nums):
        max_sum, curr_sum = float('-inf'), 0
        for num in nums:
            curr_sum = max(curr_sum, 0) + num
            max_sum = max(max_sum, curr_sum)
        
        return max_sum
        