class Solution(object):
    def largestGoodInteger(self, num):
        ans, flag = 0, False
        n = len(num)
        if n < 3:
            return ""

        for i in range(2, n):
            if num[i] == num[i - 1] and num[i] == num[i - 2]:
                ans = max(ans, int(num[i]))
                flag = True

        return str(ans) * 3 if flag else ""
        