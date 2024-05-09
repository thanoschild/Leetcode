class Solution(object):
    def maximumHappinessSum(self, happiness, k):
        happiness.sort(reverse = True)
        ans = 0

        for i in range(k):
            happiness[i] = max(0, happiness[i] - i)
            ans += happiness[i]
        
        return ans
        