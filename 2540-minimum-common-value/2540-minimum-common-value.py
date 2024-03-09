class Solution(object):
    def getCommon(self, nums1, nums2):
        n, m, i, j = len(nums1), len(nums2), 0, 0

        while i < n and j < m:
            if nums1[i] > nums2[j]:
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                return nums2[j]
        
        return -1
        