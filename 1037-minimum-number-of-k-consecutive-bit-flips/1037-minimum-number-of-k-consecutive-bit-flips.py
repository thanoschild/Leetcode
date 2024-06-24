class Solution(object):
    def minKBitFlips(self, nums, k):
        n, curr_window_flips, ans = len(nums), 0, 0
        for i in range(n):
            if i - k >= 0 and nums[i-k] == 2:
                curr_window_flips -= 1
            
            if (nums[i] + curr_window_flips) % 2 == 0:
                if i + k > n:
                    return -1
                ans += 1
                curr_window_flips += 1
                nums[i] = 2
        
        return ans

        