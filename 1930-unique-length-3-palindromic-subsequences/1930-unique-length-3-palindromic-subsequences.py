class Solution(object):
    def countPalindromicSubsequence(self, s):
        minIdx = [float('inf')]*26
        maxIdx = [float('-inf')]*26
        
        n, count = len(s), 0
        for i in range(n):
            idx = ord(s[i]) - ord('a')
            minIdx[idx] = min(minIdx[idx], i)
            maxIdx[idx] = max(maxIdx[idx], i)
            
        for i in range(26):
            if minIdx[i] == float('inf') or maxIdx[i] == float('-inf'):
                continue
            
            st = set()
            for j in range(minIdx[i] + 1, maxIdx[i]):
                st.add(s[j])
            count += len(st)
            
        return count
        