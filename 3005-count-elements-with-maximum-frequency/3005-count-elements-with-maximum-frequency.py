class Solution(object):
    def maxFrequencyElements(self, nums):
        mp = {}
        count, max_freq = 0, 0

        for x in nums:
            if x in mp:
                mp[x] += 1
            else:
                mp[x] = 1

            if mp[x] > max_freq:
                max_freq = mp[x]
                count = 0
            
            if mp[x] == max_freq:
                count += 1
        
        return count * max_freq
        