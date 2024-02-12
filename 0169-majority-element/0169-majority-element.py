class Solution(object):
    def majorityElement(self, nums):
        count, ele = 0, 0
        for it in nums:
            if count == 0: ele = it
            if ele == it: count += 1
            else: count -= 1
        
        return ele
        