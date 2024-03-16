class Solution(object):
    def findMaxLength(self, nums):
        n, sum, max_len = len(nums), 0, 0
        mp = {}
        mp[0] = -1

        for i in range(n):
            sum += 1 if nums[i] == 1 else -1
            if sum in mp:
                max_len = max(max_len, i - mp[sum])
            else:
                mp[sum] = i
        
        return max_len
        