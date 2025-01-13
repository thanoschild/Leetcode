class Solution(object):
    def minimumLength(self, s):
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord('a')] += 1
        
        ans = 0
        for n in freq:
            if n == 0:
                continue
            elif n % 2 == 0:
                ans += 2
            else:
                ans += 1
        
        return ans
        