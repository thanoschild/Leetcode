class Solution(object):
    def minOperations(self, nums, k):
        _xor, count = 0, 0
        for num in nums:
            _xor ^= num

        while k > 0 or _xor > 0:
            if (k % 2) != (_xor % 2):
                count += 1
            k //= 2
            _xor //= 2
        
        return count
        