class Solution(object):
    def wonderfulSubstrings(self, word):
        ans, _xor = 0, 0
        mp = {}
        mp[0] = 1

        for c in word:
            bit = ord(c) - ord('a')
            _xor ^= (1 << bit)
            for i in range(10):
                ans += mp[_xor ^ (1 << i)] if _xor ^ (1 << i) in mp else 0
            ans += mp[_xor] if _xor in mp else 0
            if _xor in mp:
                mp[_xor] += 1
            else:
                mp[_xor] = 1
        
        return ans