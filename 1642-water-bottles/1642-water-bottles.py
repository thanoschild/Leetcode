class Solution(object):
    def numWaterBottles(self, numBottles, numExchange):
        ans = numBottles
        while numBottles >= numExchange:
            rem = numBottles % numExchange
            numBottles /= numExchange
            ans += numBottles
            numBottles += rem
        
        return ans
        