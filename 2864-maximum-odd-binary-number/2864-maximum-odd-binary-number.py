class Solution(object):
    def maximumOddBinaryNumber(self, s):
        ones, zeros = 0, 0
        for c in s:
            if c == '1':
                ones += 1
            else:
                zeros += 1
        
        ans = ''
        ones -= 1
        while ones > 0:
            ans += '1'
            ones -= 1
        while zeros > 0:
            ans += '0'
            zeros -= 1
        
        ans += '1'

        return ans
        