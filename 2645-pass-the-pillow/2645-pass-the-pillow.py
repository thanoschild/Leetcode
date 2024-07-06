class Solution(object):
    def passThePillow(self, n, time):
        time %= (n*2 - 2)
        return n - abs(n - 1 - time)
        