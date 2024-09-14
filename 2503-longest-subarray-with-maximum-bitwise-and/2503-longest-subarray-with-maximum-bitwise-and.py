class Solution(object):
    def longestSubarray(self, nums):
        mx, count, ans = 0, 0, 0
        for n in nums:
            mx = max(n, mx)
        
        for n in nums:
            if mx == n:
                count += 1
            else:
                count = 0
            ans = max(ans, count)
        
        return ans
        