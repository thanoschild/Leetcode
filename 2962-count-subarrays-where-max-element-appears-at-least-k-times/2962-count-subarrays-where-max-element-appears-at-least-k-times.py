class Solution(object):
    def countSubarrays(self, nums, k):
        n, ans, count, max_ele = len(nums), 0, 0, max(nums)

        i, j = 0, 0
        while j < n:
            if nums[j] == max_ele:
                count += 1
            while count >= k:
                ans += (n - j)
                if nums[i] == max_ele:
                    count -= 1
                i += 1
            j += 1
        
        return ans
        