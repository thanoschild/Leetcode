class Solution(object):
    def solve(self, low, high, i, num, ans):
        if num >= low and num <= high:
            ans.append(num)
        if num > high or i > 9:
            return
        self.solve(low, high, i+1, num*10 + i, ans)
        
    def sequentialDigits(self, low, high):
        ans = []
        for i in range(1, 10):
            self.solve(low, high, i, 0, ans)
        ans.sort()
        return ans
        