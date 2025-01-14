class Solution(object):
    def findThePrefixCommonArray(self, A, B):
        n, count = len(A), 0
        freq = [0] * (n + 1)
        ans = []

        for i in range(n):
            freq[A[i]] += 1
            if freq[A[i]] == 2:
                count += 1
            freq[B[i]] += 1
            if freq[B[i]] == 2:
                count += 1
            ans.append(count)
        
        return ans
        