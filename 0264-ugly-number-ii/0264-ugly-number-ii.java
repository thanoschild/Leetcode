class Solution {
    public int nthUglyNumber(int n) {
        int k2 = 0, k3 = 0, k5 = 0;
        int[] dp = new int[n+1];
        dp[0] = 1;

        for(int i = 1; i<=n; i++) {
            dp[i] = Math.min(2*dp[k2], Math.min(3*dp[k3], 5*dp[k5]));
            if(dp[i] == 2*dp[k2]) k2++;
            if(dp[i] == 3*dp[k3]) k3++;
            if(dp[i] == 5*dp[k5]) k5++;
        }

        return dp[n-1];
    }
}