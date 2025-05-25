class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> freq(26, vector<int>(26, 0));
        int ans = 0;

        for(string word : words) {
            int a = word[0] - 'a', b = word[1] - 'a';
            if(freq[b][a]) {
                ans += 4; 
                freq[b][a]--;
            } else {
                freq[a][b]++;
            }
        }

        for(int i = 0; i<26; i++) {
            if(freq[i][i]) {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};