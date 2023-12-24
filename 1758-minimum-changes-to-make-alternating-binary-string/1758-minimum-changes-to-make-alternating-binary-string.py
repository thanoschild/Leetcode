class Solution(object):
    def minOperations(self, s):
        count, n = 0, len(s)
        for i in range(n):
            if ord(s[i]) - ord('0') != i % 2: count+=1
        
        return min(count, n - count)
        