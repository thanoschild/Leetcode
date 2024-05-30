class Solution(object):
    def countTriplets(self, arr):
        n, ans = len(arr) + 1, 0
        prefix = [0] * n

        for i in range(1, n):
            prefix[i] = prefix[i-1] ^ arr[i-1]
        
        for i in range(0, n):
            for j in range(i+1, n):
                if prefix[i] == prefix[j]:
                    ans += (j - i - 1)
        
        return ans
        