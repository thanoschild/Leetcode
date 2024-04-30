class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0, _xor = 0;
        unordered_map<long long, long long> mp;
        mp[0] = 1;

        for(char c : word) {
            int bit = c - 'a';
            _xor ^= (1 << bit);
            for(int i = 0; i<10; i++) ans += mp[_xor ^ (1 << i)];
            ans += mp[_xor];
            mp[_xor]++;
        }

        return ans;
    }
};