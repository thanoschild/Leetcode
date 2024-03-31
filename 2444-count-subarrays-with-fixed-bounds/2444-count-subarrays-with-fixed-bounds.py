class Solution(object):
    def countSubarrays(self, nums, minK, maxK):
        n, min_idx, max_idx, bad_idx, ans = len(nums), -1, -1, 0, 0

        for i in range(n):
            if nums[i] < minK or nums[i] > maxK: bad_idx = i + 1
            if nums[i] == minK: min_idx = i
            if nums[i] == maxK: max_idx = i
            ans += max(0, min(max_idx, min_idx) - bad_idx + 1)
        
        return ans
        