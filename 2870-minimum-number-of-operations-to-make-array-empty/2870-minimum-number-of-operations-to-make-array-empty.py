class Solution(object):
    def minOperations(self, nums):
        mp = {}
        for n in nums:
            mp[n] = mp.get(n, 0) + 1
        count = 0

        for key, value in mp.items():
            if value == 1:
                return -1
            count += value//3
            if value % 3 != 0:
                count += 1
            
        return count
        