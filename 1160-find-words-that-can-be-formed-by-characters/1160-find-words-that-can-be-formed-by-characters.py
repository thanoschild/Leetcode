class Solution(object):
    def countCharacters(self, words, chars):
        char_count_map = Counter(chars)

        ans = 0

        for word in words:
            curr_map = Counter(chars)
            flag = True

            for c in word:
                if curr_map[c] > 0:
                    curr_map[c] -= 1
                else:
                    flag = False
                    break

            if flag:
                ans += len(word)

        return ans
        