class Solution(object):
    def kthDistinct(self, arr, k):
        mp = {}
        for s in arr:
            if s in mp:
                mp[s] += 1
            else:
                mp[s] = 1
        
        for s in arr:
            if mp[s] == 1:
                k -= 1
                if k == 0:
                    return s
            
        return ""
        