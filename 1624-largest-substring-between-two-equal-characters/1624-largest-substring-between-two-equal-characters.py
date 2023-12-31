class Solution(object):
    def maxLengthBetweenEqualCharacters(self, s):
        seen = [-1] * 26
        ans = -1

        for i in range(len(s)):
            if seen[ord(s[i]) - ord('a')] != -1:
                ans = max(ans, i - seen[ord(s[i]) - ord('a')] - 1)
                continue
            seen[ord(s[i]) - ord('a')] = i

        return ans
        