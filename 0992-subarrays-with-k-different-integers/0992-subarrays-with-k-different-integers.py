class Solution(object):
    def find_k_most_subarrays(sefl, nums, n, k):
        i, j, count = 0, 0, 0
        mp = {}

        while j < n:
            if nums[j] in mp:
                mp[nums[j]] += 1
            else:
                mp[nums[j]] = 1
            while len(mp) > k:
                mp[nums[i]] -= 1
                if mp[nums[i]] == 0:
                    del mp[nums[i]]
                i += 1
            count += (j - i + 1)
            j += 1
        
        return count

    def subarraysWithKDistinct(self, nums, k):
        n = len(nums)
        ans1 = self.find_k_most_subarrays(nums, n, k)
        ans2 = self.find_k_most_subarrays(nums, n, k-1)
        return ans1 - ans2
        
        