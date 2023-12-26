class Solution {
    int dp[][];
    final int mod = (int) 1e9 + 7;

    int solve(int n, int k, int target) {
        if(n == 0 && target == 0) return 1;
        if(n < 0 || target < 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];

        int sum = 0;
        for(int i = 1; i<=k; i++) {
           sum = (sum%mod + solve(n-1, k, target - i)%mod)%mod;
        }
        dp[n][target] = sum;
        return dp[n][target];
    }

    public int numRollsToTarget(int n, int k, int target) {
        dp = new int[31][1001];
        for(int i = 0; i<31; i++) {
            Arrays.fill(dp[i], -1);
        }

        return solve(n, k, target);
    }
}