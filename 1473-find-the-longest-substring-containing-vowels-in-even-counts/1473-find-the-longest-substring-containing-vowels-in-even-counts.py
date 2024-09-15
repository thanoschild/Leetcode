class Solution(object):
    def findTheLongestSubstring(self, s):
        mp = {0: -1}
        ans, mask, v = 0, 0, "aeiou"

        for i in range(len(s)):
            for j in range(len(v)):
                if v[j] == s[i]:
                    mask = mask ^ (1 << j)
                    break
            
            if mask not in mp:
                mp[mask] = i
            
            ans = max(ans, i - mp[mask])
        
        return ans
        