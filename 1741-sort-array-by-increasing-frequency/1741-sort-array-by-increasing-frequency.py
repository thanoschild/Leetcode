class Solution(object):
    def frequencySort(self, nums):
        freq_map = Counter(nums)
        nums.sort(key=lambda x: (freq_map[x], -x))

        return nums
        