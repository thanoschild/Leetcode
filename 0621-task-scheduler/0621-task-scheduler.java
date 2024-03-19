class Solution(object):
    def leastInterval(self, tasks, n):
        mp = {}
        max_count = 0
        for x in tasks:
            if x in mp:
                mp[x] += 1
            else:
                mp[x] = 1
            max_count = max(max_count, mp[x])
        
        ans = (max_count - 1) * (n + 1)
        for key, value in mp.items():
            if value == max_count:
                ans += 1
        
        return max(ans, len(tasks))
        