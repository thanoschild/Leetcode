class Solution(object):
    def removeKdigits(self, num, k):
        n, ans = len(num), []
        ans += num[0]

        for x in num[1:]:
            while len(ans) > 0 and x < ans[-1] and k > 0:
                ans.pop()
                k -= 1
            if x != '0' or len(ans) > 0:
                ans += x
            
        while len(ans) > 0 and k > 0:
            ans.pop()
            k -= 1
        
        return ''.join(ans) if len(ans) > 0 else "0"
        