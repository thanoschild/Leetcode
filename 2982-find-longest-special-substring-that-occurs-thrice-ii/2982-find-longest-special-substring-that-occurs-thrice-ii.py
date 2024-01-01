class Solution(object):
    def check(self, mid, a):
        count = 0
        for x in a:
            count += max(0, x - mid + 1)

        return count >= 3

    def maximumLength(self, s):
        n = len(s)
        freq = [[] for _ in range(26)]

        count = 1
        for i in range(1, n):
            if s[i] != s[i-1]:
                freq[ord(s[i-1]) - ord('a')].append(count)
                count = 1
            else:
                count += 1
        freq[ord(s[-1]) - ord('a')].append(count)
            
        ans = -1
        for i in range(26):
            if len(freq[i]) == 0:
                continue
            freq[i].sort()
            start, end = 1, freq[i][-1]

            while start <= end:
                mid = start + (end - start)//2
                if self.check(mid, freq[i]) == True:
                    ans = max(ans, mid)
                    start = mid + 1
                else:
                    end = mid - 1
                
        return ans

        