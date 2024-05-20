class Solution(object):
    def subsetXORSum(self, nums):
        n = len(nums)
        ans = 0
        for i in range(1, (1 << n)):
            total = 0
            for j in range(0, n):
                if (i & (1 << j)) >= 1:
                    total ^= nums[j]
            ans += total
        
        return ans
        