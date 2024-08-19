class Solution {
public:
    int solve(int count, int paste, vector<vector<int>> &dp, int n) {
        if(count == n) return 0;
        if(count > n) return 1000;
        if(dp[count][paste] != -1) return dp[count][paste];

        int ans1 = 1 + solve(count + paste, paste, dp, n);
        int ans2 = 2 + solve(count + count, count, dp, n);
        return dp[count][paste] = min(ans1, ans2);
    }

    int minSteps(int n) {
        if(n == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return 1 + solve(1, 1, dp, n);
    }
};