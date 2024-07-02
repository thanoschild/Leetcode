class Solution(object):
    def intersect(self, nums1, nums2):
        ans = []
        mp = {}
        for it in nums1:
            if it in mp:
                mp[it] += 1
            else:
                mp[it] = 1
        
        for it in nums2:
            if it in mp and mp[it] > 0:
                ans.append(it)
                mp[it] -= 1
        
        return ans
        