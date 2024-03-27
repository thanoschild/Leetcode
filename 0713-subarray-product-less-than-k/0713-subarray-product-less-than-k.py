class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        n = len(nums)
        count, pro = 0, 1
        i, j = 0, 0

        while j < n:
            pro *= nums[j]
            while i <= j and pro >= k:
                pro /= nums[i]
                i += 1
            count += (j - i + 1)
            j += 1
        
        return count
        