class Solution(object):
    def isIsomorphic(self, s, t):
        if len(s) != len(t):
            return False
        map_s, map_t = {}, {}

        for i in range(len(s)):
            if s[i] in map_s and map_s[s[i]] != t[i]:
                return False
            if t[i] in map_t and map_t[t[i]] != s[i]:
                return False
            
            map_s[s[i]] = t[i]
            map_t[t[i]] = s[i]
        
        return True
        