class Solution(object):
    def maximumLength(self, s):
        n, mp = len(s), {}

        for i in range(n):
            curr = s[i]
            if curr in mp:
                mp[curr] += 1
            else:
                mp[curr] = 1

            for j in range(i, n - 1):
                if s[j] == s[j+1]:
                    curr += s[j]
                    if curr in mp:
                        mp[curr] += 1
                    else:
                        mp[curr] = 1
                else:
                    break
        
        ans = 0
        for key, value in mp.items():
            if value >= 3:
                ans = max(ans, len(key))
        
        return ans if ans != 0 else -1
        