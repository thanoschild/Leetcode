class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> up(26, 0), low(26, 0);
        for(char c : s) {
            if(c >= 'a') low[c - 'a']++;
            else up[c - 'A']++;
        }

        int ans = 0, flag = 0;
        for(int i = 0; i<26; i++) {
            if(low[i] % 2 == 0) ans += low[i];
            else {
                ans += low[i] - 1;
                flag = 1;
            }

            if(up[i]%2 == 0) ans += up[i];
            else {
                ans += up[i] - 1;
                flag = 1;
            }
        }

        return ans + flag;
    }
};