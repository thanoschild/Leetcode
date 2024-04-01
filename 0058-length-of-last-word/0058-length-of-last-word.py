class Solution(object):
    def lengthOfLastWord(self, s):
        idx, ans = len(s) - 1, 0
        while idx >= 0 and s[idx] == ' ': idx -= 1
        while idx >= 0 and s[idx] != ' ':
            idx -= 1
            ans += 1
        
        return ans
        