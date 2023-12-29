class Solution {
    int[][] dp;

    int solve(int[] jobdiff, int idx, int days, int n) {
        if(idx == n && days == 0) return 0;
        if(idx == n || days == 0 || n - idx < days) return 1000009;
        if(dp[idx][days] != -1) return dp[idx][days];

        int ans = 1000009, maxele = Integer.MIN_VALUE;
        for(int i = idx; i<n; i++) {
            maxele = Math.max(maxele, jobdiff[i]);
            ans = Math.min(ans, maxele + solve(jobdiff, i + 1, days - 1, n));
        }

        dp[idx][days] = ans;
        return dp[idx][days];
    }

    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;
        if(n < d) return -1;
        dp = new int[n+1][d+1];
        for(int i = 0; i<=n; i++) {
           Arrays.fill(dp[i], -1);
        }
        return solve(jobDifficulty, 0, d, n);
    }
}