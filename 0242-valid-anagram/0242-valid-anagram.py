class Solution(object):
    def isAnagram(self, s, t):
        freq = [0]*26
        for c in s:
            freq[ord(c) - ord('a')] += 1
        for c in t:
            freq[ord(c) - ord('a')] -= 1
        for x in freq:
            if x != 0:
                return False
        return True
        