class Solution(object):
    def maxProduct(self, nums):
        n1, n2 = 0, 0
        for n in nums:
            if n > n1:
                n2 = n1
                n1 = n
            else:
                n2 = max(n, n2)
        
        return (n1 - 1)*(n2 - 1)
        