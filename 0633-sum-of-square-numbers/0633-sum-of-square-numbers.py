class Solution(object):
    def judgeSquareSum(self, c):
        i = 0
        while i*i <= c:
            a = sqrt(c - i*i)
            if a == int(a):
                return True
            i += 1
        return False
        