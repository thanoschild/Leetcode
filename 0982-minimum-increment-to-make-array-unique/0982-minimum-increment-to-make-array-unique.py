class Solution(object):
    def minIncrementForUnique(self, nums):
        nums.sort()
        ans, need = 0, 0
        for n in nums:
            ans += max(need - n, 0)
            need = max(n, need) + 1
        
        return ans
        