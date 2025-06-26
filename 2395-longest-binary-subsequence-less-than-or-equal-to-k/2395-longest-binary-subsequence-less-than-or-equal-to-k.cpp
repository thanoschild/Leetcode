class Solution {
public: 
   int solve(int i, int bit, int sum, string &s, vector<vector<int>> &dp){
        if(i < 0) return 0;
        if(dp[i][bit] != -1) return dp[i][bit];
            
        int x = solve(i-1, bit, sum, s, dp);
        int y = 0;
        if(sum - (s[i] - '0')*pow(2,bit) >= 0){
          y = 1 + solve(i-1, bit + 1, sum - (s[i] - '0')*pow(2,bit), s, dp);
        }
            
        return dp[i][bit] = max(x, y);
    }
    int longestSubsequence(string s, int k) {
       int n = s.size();
       vector<vector<int>> dp(n, vector<int>(n, -1));
       return solve(n-1, 0, k, s, dp);
    }
};