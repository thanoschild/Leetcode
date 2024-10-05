class Solution(object):
    def checkInclusion(self, s1, s2):
        n, m = len(s1), len(s2)
        if n > m:
            return False

        freq1, freq2 = [0]* 26, [0] * 26
        for i in range(n):
            freq1[ord(s1[i]) - ord('a')] += 1
        for i in range(n):
            freq2[ord(s2[i]) - ord('a')] += 1
        
        if freq1 == freq2:
            return True
        
        for i in range(n, m):
            freq2[ord(s2[i - n]) - ord('a')] -= 1
            freq2[ord(s2[i]) - ord('a')] += 1
            if freq1 == freq2:
                return True
        
        return False
