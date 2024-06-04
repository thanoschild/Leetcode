class Solution(object):
    def longestPalindrome(self, s):
        lower = [0] * 26
        upper = [0] * 26

        for char in s:
            if char.islower():
                lower[ord(char) - ord('a')] += 1
            else:
                upper[ord(char) - ord('A')] += 1

        result = 0
        has_odd = 0

        for count in lower + upper:
            if count % 2 == 0:
                result += count
            else:
                result += count - 1
                has_odd = 1

        return result + has_odd
        