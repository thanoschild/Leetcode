class Solution(object):
    def sum_digit(self, num):
        ans = 0
        while num > 0:
            ans += num % 10
            num //= 10
        return ans

    def getLucky(self, s, k):
        total_sum = 0
        for c in s:
            value = ord(c) - ord('a') + 1
            while value > 0:
                total_sum += value % 10
                value //= 10

        while k > 1:
            total_sum = self.sum_digit(total_sum)
            k -= 1

        return total_sum


        