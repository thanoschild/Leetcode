class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);
        for(char c : s) {
            freq[c - '0']++;
        }

        int ans = 0, flag = 0;
        for(int i = 0; i<128; i++) {
            if(freq[i] % 2 == 0) ans += freq[i];
            else {
                if(freq[i] > 1) {
                    ans += freq[i] - 1;
                    freq[i] = 1;
                }
                if(freq[i] == 1) flag = 1;
            }
        }

        return ans + flag;
    }
};