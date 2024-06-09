class Solution(object):
    def subarraysDivByK(self, nums, k):
        freq = [0] * k
        freq[0] = 1

        sum, rem, count = 0, 0, 0
        for n in nums:
            sum += n
            rem = sum % k
            if rem < 0: rem += k
            if freq[rem] != 0: count += freq[rem]
            freq[rem] += 1
        
        return count
        