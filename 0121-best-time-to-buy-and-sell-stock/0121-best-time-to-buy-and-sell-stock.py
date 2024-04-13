class Solution(object):
    def maxProfit(self, prices):
        profit = 0
        least = prices[0]
        for i in prices:
            if least > i :
                least = i
            profit = max(profit, i - least)
        
        return profit
        