class Solution(object):
    def at_most_k(self, nums, k):
        ans, count, j = 0, 0, 0
        for i in range(len(nums)):
            count += nums[i] % 2
            while count > k:
                count -= nums[j] % 2
                j += 1
            ans += (i - j)
        
        return ans
        
    def numberOfSubarrays(self, nums, k):
        return self.at_most_k(nums, k) - self.at_most_k(nums, k-1)
        