class Solution(object):
    def countSeniors(self, details):
        ans = 0
        for s in details:
            age = (ord(s[11]) - ord('0')) * 10 + (ord(s[12]) - ord('0'))
            if age > 60: 
                ans += 1
        
        return ans
        