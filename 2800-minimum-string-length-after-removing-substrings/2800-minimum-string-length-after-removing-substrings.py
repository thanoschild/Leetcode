class Solution(object):
    def minLength(self, s):
        ans = ""
        for c in s:
            if len(ans) > 0 and ((c == 'B' and ans[-1] == 'A') or (c == 'D' and ans[-1] == 'C')):
                ans = ans[:-1]  # Remove the last character
            else:
                ans += c

        return len(ans)
        
        