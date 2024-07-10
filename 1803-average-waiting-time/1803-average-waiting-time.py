class Solution(object):
    def averageWaitingTime(self, customers):
        ans = curr = 0.
        for c in customers:
            curr = max(curr, c[0]) + c[1]
            ans += curr - c[0]
        
        return ans / len(customers)