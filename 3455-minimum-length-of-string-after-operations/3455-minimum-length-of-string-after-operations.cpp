class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c - 'a']++;

        int ans = 0;
        for(int i = 0; i<26; i++) {
            if(freq[i] == 0) continue;
            if(freq[i] % 2) ans += 1;
            else ans += 2;
        }

        return ans;
    }
};