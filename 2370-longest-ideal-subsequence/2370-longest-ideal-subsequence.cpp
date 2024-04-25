class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int n = s.size(), ans = 0;

        for(char c : s) {
            int i = c - 'a';
            dp[i] += 1;
            for(int j = max(0, i - k); j<=min(25, i + k); j++) {
                if(i != j) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};