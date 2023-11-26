class Solution(object):
    def sortVowels(self, s):
        vowels = 'aeiouAEIOU'
        ans, i = [], 0
        k_vowels = sorted([c for c in s if c in vowels])

        for c in s:
            if c in vowels:
                ans.append(k_vowels[i])
                i += 1
            else:
                ans.append(c)

        return ''.join(ans)
        