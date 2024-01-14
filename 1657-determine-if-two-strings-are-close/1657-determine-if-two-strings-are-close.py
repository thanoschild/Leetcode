class Solution(object):
    def closeStrings(self, word1, word2):
        if len(word1) != len(word2): return False
        freq1, freq2 = [0]*26, [0]*26

        seen1 = set()
        seen2 = set()

        for i in range(len(word1)):
            freq1[ord(word1[i]) - ord('a')] += 1
            freq2[ord(word2[i]) - ord('a')] += 1

            seen1.add(word1[i])
            seen2.add(word2[i])

        freq1.sort()
        freq2.sort()

        return freq1 == freq2 and seen1 == seen2

        