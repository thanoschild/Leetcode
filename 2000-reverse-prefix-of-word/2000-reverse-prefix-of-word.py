class Solution(object):
    def reversePrefix(self, word, ch):
        ans, flag = "", True

        for c in word:
            if c == ch and flag:
                ans += c
                ans = ans[::-1]
                flag = False
            else:
                ans += c
        
        return ans

        