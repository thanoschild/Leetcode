class Solution(object):
    def minSteps(self, s, t):
        freq = [0] * 26
        for i in range(len(s)):
            freq[ord(s[i]) - ord('a')] += 1
            freq[ord(t[i]) - ord('a')] -= 1

        diff = 0
        for n in freq:
            diff += abs(n)
        
        return diff//2
        