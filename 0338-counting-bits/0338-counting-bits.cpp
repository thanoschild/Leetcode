class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 0; i<=n; i++) {
            if(i % 2) dp[i] = dp[i/2] + 1;
            else dp[i] = dp[i/2];
        }

        return dp;
    }
};