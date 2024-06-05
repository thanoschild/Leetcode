class Solution(object):
    def commonChars(self, words):
        seen = [float('inf')] * 26
        for s in words:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            for i in range(26):
                seen[i] = min(seen[i], count[i])
        
        ans = []
        for i in range(26):
            for j in range(seen[i]):
                ans.append(chr(ord('a') + i))
        
        return ans
        