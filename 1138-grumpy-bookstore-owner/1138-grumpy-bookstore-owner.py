class Solution(object):
    def maxSatisfied(self, customers, grumpy, minutes):
        n = len(customers)
        happy_customers = 0
        for i in range(n):
            if grumpy[i] == 0:
                happy_customers += customers[i]
                customers[i] = 0
        
        max_sum , _sum = 0, 0
        for i in range(n):
            _sum += customers[i]
            if i >= minutes:
                _sum -= customers[i-minutes]
            max_sum = max(max_sum, _sum)
        
        return max_sum + happy_customers
        