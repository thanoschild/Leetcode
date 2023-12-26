class Solution {
public:
    int dp[31][1001];
    const int mod = 1e9 + 7;

    int solve(int n, int k, int target) {
        if(n == 0 && target == 0) return 1;
        if(n < 0 || target < 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];

        int sum = 0;
        for(int i = 1; i<=k; i++) {
            sum = (sum%mod + solve(n - 1, k, target - i)%mod)%mod;
        }

        return dp[n][target] = sum;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, target);
    }
};