class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        return sorted(arr1, key=(arr2 + sorted(arr1)).index)
        