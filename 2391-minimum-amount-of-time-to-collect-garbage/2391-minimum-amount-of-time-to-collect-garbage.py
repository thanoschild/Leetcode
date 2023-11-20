class Solution(object):
    def garbageCollection(self, garbage, travel):
        garbage_type, ans, n, m = ['M', 'P', 'G'], 0, len(garbage), len(travel)
        
        for x in garbage_type:
            time, last_pick = 0, 0
            for i in range(n):
                count = 0
                for bin in garbage[i]:
                    if bin == x:
                        count += 1
                if count > 0:
                    time += count
                    last_pick = i
                if i < m:
                    time += travel[i]
            
            for j in range(n-2, last_pick-1, -1):
                time -= travel[j]
            
            ans += time
            
        return ans
                
                
        