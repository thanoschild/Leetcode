class Solution(object):
    def solve(self, words, count, score, idx):
        ans = 0
        for i in range(idx, len(words)):
            curr = 0
            flag = True
            for c in words[i]:
                count[ord(c) - ord('a')] -= 1
                curr += score[ord(c) - ord('a')]
                if count[ord(c) - ord('a')] < 0:
                    flag = False
            if flag:
                curr += self.solve(words, count, score, i + 1)
                ans = max(ans, curr)
            for c in words[i]:
                count[ord(c) - ord('a')] += 1
            curr = 0
        return ans

    def maxScoreWords(self, words, letters, score):
        n = len(words)
        m = len(letters)
        p = len(score)
        if n == 0 or m == 0 or p == 0:
            return 0
        count = [0] * p
        for c in letters:
            count[ord(c) - ord('a')] += 1
        return self.solve(words, count, score, 0)
        