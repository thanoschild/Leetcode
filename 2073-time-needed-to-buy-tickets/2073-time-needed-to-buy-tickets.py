class Solution(object):
    def timeRequiredToBuy(self, tickets, k):
        ans, n = 0, len(tickets)
        for i in range(n):
            val = tickets[k] - 1 if i > k else tickets[k] 
            ans += min(tickets[i], val)
        
        return ans
        