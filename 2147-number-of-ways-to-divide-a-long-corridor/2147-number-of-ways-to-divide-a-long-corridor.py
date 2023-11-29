class Solution(object):
    def numberOfWays(self, s):
        seats, n, mod = 0, len(s), 10**9 + 7
        for x in s:
            if x == 'S':
                seats += 1
            
        if seats == 0 or seats % 2 == 1:
            return 0
        
        ans, count, plant = 1, 0, 0
        for i in range(n):
            if s[i] == 'S':
                count += 1
            if count == 2:
                i += 1
                plant = 1
                while i < n and s[i] == 'P':
                    plant += 1
                    i += 1
                if i == n:
                    break
                ans = (ans * plant)%mod
                count = 0
                i -= 1
                
        return ans
        