class Solution(object):
    def numberOfBeams(self, bank):
        ans, count, prev = 0, 0, 0
        for s in bank:
            count = 0
            for c in s:
                if c == '1': count += 1
            if count != 0:
                ans += (prev * count)
                prev = count
        
        return ans

        