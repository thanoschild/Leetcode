class Solution(object):
    def maxLength(self, arr):
        dp = [set()]

        ans = 0

        for s in arr:
            st = set(s)
            if len(st) < len(s):
                continue

            for c in reversed(dp):
                if st & c:
                    continue

                dp.append(st | c)
                ans = max(ans, len(st) + len(c))

        return ans
        