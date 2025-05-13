class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int mod = 1e9 + 7;
        vector<long long> freq(26, 0);

        for(char c : s) freq[c - 'a']++;

        for(int i = 0; i<t; i++) {
            vector<long long> temp(26, 0);
            for(int j = 0; j<26; j++) {
                if(j == 25) {
                    temp[0] = (temp[0] + freq[j]) % mod;
                    temp[1] = (temp[1] + freq[j]) % mod;
                } else {
                    temp[j+1] = (temp[j+1] + freq[j]) % mod;
                }
            }
            freq = temp;
        }

        long long len = 0;
        for(auto it : freq) len = (len + it) % mod;

        return (int) len;
    }
};