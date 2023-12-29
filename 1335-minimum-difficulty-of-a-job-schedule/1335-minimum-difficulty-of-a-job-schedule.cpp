class Solution {
public:
    int dp[301][11];

    int solve(vector<int> &jobdiff, int start, int days, int n) {
        if(start == n && days == 0) return 0;
        if(start == n || days == 0 || n - start < days) return 1000009;
        if(dp[start][days] != -1) return dp[start][days];

        int ans = 1000009, maxele = INT_MIN;
        for(int i = start; i<n; i++) {
            maxele = max(maxele, jobdiff[i]);
            ans = min(ans, maxele + solve(jobdiff, i + 1, days - 1, n));
        }
        dp[start][days] = ans;

        return dp[start][days];
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
       int n = jobDifficulty.size();
       if(n < d) return -1;
       memset(dp, -1, sizeof(dp));
       return solve(jobDifficulty, 0, d, n); 
    }
};