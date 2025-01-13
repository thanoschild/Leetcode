class Solution {
public:
    int remChar(int n) {
        while(n >= 3) {
            n -= 2;
        }
        return n;
    }

    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c - 'a']++;
        int ans = 0;
        for(int i = 0; i<26; i++) {
            ans += remChar(freq[i]);
        }

        return ans;
    }
};