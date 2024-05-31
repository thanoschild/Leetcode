class Solution(object):
    def singleNumber(self, nums):
        _xor = 0
        for num in nums:
            _xor ^= num

        right_bit = _xor & (- _xor) 
        x, y = 0, 0

        for num in nums:
            if (right_bit & num) == 0:
                x ^= num
            else:
                y ^= num
        
        return [x, y]

        