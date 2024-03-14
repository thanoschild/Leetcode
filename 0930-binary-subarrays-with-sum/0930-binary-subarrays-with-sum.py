class Solution(object):
    def numSubarraysWithSum(self, nums, goal):
        mp = {0: 1}
        ans, _sum = 0, 0
        for it in nums:
            _sum += it
            ans += mp.get(_sum - goal, 0)
            mp[_sum] = mp.get(_sum, 0) + 1
        return ans