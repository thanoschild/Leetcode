class Solution(object):
    def maxFrequency(self, nums, k):
        freq, sum, left = 0, 0, 0
        nums.sort()
        for right in range(len(nums)):
            sum += nums[right]
            while sum + k < nums[right] * (right - left + 1):
                sum -= nums[left]
                left += 1
            freq = max(freq, (right - left + 1))
        return freq
        