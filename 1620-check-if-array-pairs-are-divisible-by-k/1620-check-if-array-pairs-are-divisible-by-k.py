class Solution(object):
    def canArrange(self, arr, k):
        freq = [0] * k
        for it in arr:
            rem = (it % k + k) % k
            freq[rem] += 1
        
        for i in range(1, k//2 + 1):
            if freq[i] != freq[k - i]:
                return False
        
        return freq[0] % 2 == 0
        