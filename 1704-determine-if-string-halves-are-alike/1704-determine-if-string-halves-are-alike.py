class Solution(object):
    def halvesAreAlike(self, s):
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        n, count1, count2 = len(s), 0, 0

        for i in range(n//2):
            if s[i] in vowels: count1 += 1
            if s[i + n//2] in vowels: count2 += 1
        
        return count1 == count2
        