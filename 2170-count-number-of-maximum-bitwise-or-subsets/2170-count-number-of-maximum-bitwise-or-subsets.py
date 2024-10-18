class Solution(object):
    def __init__(self):
        self.ans = 0

    def max_subset(self, nums, idx, curr_or, max_or):
        if idx == len(nums):
            if curr_or == max_or:
                self.ans += 1
            return
        
        self.max_subset(nums, idx+1, curr_or | nums[idx], max_or)
        self.max_subset(nums, idx+1, curr_or, max_or)

    def countMaxOrSubsets(self, nums):
        max_or = 0
        self.ans = 0

        for n in nums: 
            max_or |= n
        self.max_subset(nums, 0, 0, max_or)
        return self.ans
        