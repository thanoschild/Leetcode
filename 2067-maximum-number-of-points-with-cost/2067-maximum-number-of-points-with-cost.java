class Solution {
    public long maxPoints(int[][] arr) {
        int n = arr.length, m = arr[0].length;
        long[][] dp = new long[n][m];

        for (int j = 0; j < m; j++) {
            dp[0][j] = arr[0][j];
        }

        for (int i = 1; i < n; i++) {
            long[] left_dp = new long[m];
            long[] right_dp = new long[m];

            left_dp[0] = dp[i - 1][0];  
            for (int j = 1; j < m; j++) {
                left_dp[j] = Math.max(left_dp[j - 1], dp[i - 1][j] + j);
            }

            right_dp[m - 1] = dp[i - 1][m - 1] - (m - 1);  
            for (int j = m - 2; j >= 0; j--) {
                right_dp[j] = Math.max(right_dp[j + 1], dp[i - 1][j] - j);
            }

            for (int j = 0; j < m; j++) {
                dp[i][j] = Math.max(left_dp[j] - j, right_dp[j] + j) + arr[i][j];
            }
        }
        
        long ans = Long.MIN_VALUE;
        for (long points : dp[n - 1]) {
            ans = Math.max(ans, points);
        }

        return ans;
    }
}