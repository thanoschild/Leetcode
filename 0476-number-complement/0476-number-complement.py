class Solution(object):
    def findComplement(self, num):
        mask, temp = 0, num
        while temp > 0:
            mask = (mask << 1) | 1
            temp >>= 1
        
        return mask ^ num
        