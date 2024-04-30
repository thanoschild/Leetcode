class Solution {
    public long wonderfulSubstrings(String word) {
        long ans = 0, _xor = 0;
        HashMap<Long, Long> mp = new HashMap<>();
        mp.put(0L, 1L);

        for(char c : word.toCharArray()) {
            int bit = c - 'a';
            _xor ^= (1 << bit);
            for(int i = 0; i<10; i++) ans += mp.getOrDefault(_xor ^ (1 << i), 0L);
            ans += mp.getOrDefault(_xor, 0L);
            mp.put(_xor, mp.getOrDefault(_xor, 0L) + 1L);
        }

        return ans;
    }
}