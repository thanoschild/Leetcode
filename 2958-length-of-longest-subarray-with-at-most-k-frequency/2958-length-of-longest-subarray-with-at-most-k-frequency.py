class Solution(object):
    def maxSubarrayLength(self, nums, k):
        n, ans = len(nums), 0
        mp = {}

        i, j = 0, 0
        while j < n:
            if nums[j] in mp:
                mp[nums[j]] += 1
            else:
                mp[nums[j]] = 1
                
            if mp[nums[j]] > k:
                while nums[i] != nums[j]:
                    mp[nums[i]] -= 1
                    i += 1
                mp[nums[i]] -= 1
                i += 1
            ans = max(ans, j - i + 1)
            j += 1
        
        return ans
        