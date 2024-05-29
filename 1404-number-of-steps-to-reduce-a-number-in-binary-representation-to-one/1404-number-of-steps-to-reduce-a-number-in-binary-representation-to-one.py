class Solution(object):
    def numSteps(self, s):
        ans, carry = 0, 0
        for i in range(len(s)-1, 0, -1):
            if ord(s[i]) - ord('0') + carry == 1:
                ans += 1
                carry = 1
            ans += 1
        
        return ans + carry

        