class Solution(object):
    def minBitFlips(self, start, goal):
        _xor, count = start ^ goal, 0
        for i in range(32):
            if _xor & (1 << i):
                count += 1
        
        return count
        