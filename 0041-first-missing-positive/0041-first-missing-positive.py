class Solution(object):
    def firstMissingPositive(self, nums):
        n = len(nums)
        seen = [0] * (n + 1)

        for x in nums:
            if x >= 0 and x <= n:
                seen[x] = 1
        
        for i in range(1, n + 1):
            if seen[i] == 0:
                return i
        
        return n + 1
        