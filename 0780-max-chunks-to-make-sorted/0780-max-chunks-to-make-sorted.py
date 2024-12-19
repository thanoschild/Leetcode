class Solution(object):
    def maxChunksToSorted(self, arr):
        n, ans, max_val = len(arr), 0, 0
        
        for i in range(n):
            max_val = max(max_val, arr[i])
            if max_val == i:
                ans += 1
        
        return ans
        