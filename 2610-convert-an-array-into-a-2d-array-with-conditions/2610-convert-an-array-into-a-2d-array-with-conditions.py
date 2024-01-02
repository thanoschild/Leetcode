class Solution(object):
    def findMatrix(self, nums):
        max_freq = 0
        freq = [0]*(len(nums) + 1)

        for x in nums:
            freq[x] += 1
            max_freq = max(max_freq, freq[x])
        
        ans = [[] for _ in range(max_freq)]
        for i in range(len(freq)):
            for j in range(freq[i]):
                ans[j].append(i)

        return ans

        