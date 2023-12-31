class Solution(object):
    def maximumLength(self, s):
        mp = {}
        n = len(s)

        for i in range(n):
            count = 1
            key = (s[i], count)
            mp[key] = mp.get(key, 0) + 1

            for j in range(i, n-1):
                if s[j] == s[j+1]:
                    count += 1
                    key2 = (s[j], count)
                    mp[key2] = mp.get(key2, 0) + 1
                else:
                    break
            
        ans = 0
        for key, value in mp.items():
            if value >= 3:
                ans = max(ans, key[1])
        
        return -1 if ans == 0 else ans
        