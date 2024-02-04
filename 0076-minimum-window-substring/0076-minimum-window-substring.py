class Solution(object):
    def minWindow(self, s, t):
        n, m = len(s), len(t)
        if n == 0 or m == 0 or m > n: return ""
        freq = [0] * 256
        for c in t:
            freq[ord(c)] += 1

        start, end, _len, count, ans = 0, 0, float('inf'), 0, 0
        while end < n:
            if freq[ord(s[end])] > 0: count += 1
            freq[ord(s[end])] -= 1
            while count == m:
                if _len > end - start + 1:
                    _len = end - start + 1
                    ans = start
                freq[ord(s[start])] += 1
                if freq[ord(s[start])] > 0: count -= 1
                start += 1
            end += 1
        
        return "" if _len == float('inf') else s[ans: ans + _len]
        