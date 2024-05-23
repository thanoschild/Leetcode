class Solution(object):
    def dfs(self, nums, idx, mp, ans, k):
        if idx == len(nums):
            ans[0] += 1
            return

        if mp.get(nums[idx] - k, 0) == 0 and mp.get(nums[idx] + k, 0) == 0:
            mp[nums[idx]] = mp.get(nums[idx], 0) + 1
            self.dfs(nums, idx + 1, mp, ans, k)
            mp[nums[idx]] -= 1

        self.dfs( nums, idx + 1, mp, ans, k)
        
    def beautifulSubsets(self, nums, k):
        ans = [0]
        mp = {}
        self.dfs(nums, 0, mp, ans, k)
        return ans[0] - 1
        