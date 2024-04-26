class Solution {
    public int minFallingPathSum(int[][] grid) {
        int n = grid.length;
        int[] dp = new int[n];

        for(int i = 0; i<n; i++) {
            dp[i] = grid[n-1][i];
        }

        for(int i = n - 2; i>=0; i--) {
            int firstMin = Integer.MAX_VALUE, secondMin = Integer.MAX_VALUE, idx = -1;
            for(int j = 0; j<n; j++) {
                if(firstMin > dp[j]) {
                    secondMin = firstMin;
                    firstMin = dp[j];
                    idx = j;
                }
                else if(secondMin > dp[j]) {
                    secondMin = dp[j];
                }
            }

            for(int j = 0; j<n; j++) {
                if(j == idx) dp[j] = secondMin + grid[i][j];
                else dp[j] = firstMin + grid[i][j];
            }
        }

        int ans = Integer.MAX_VALUE;
        for(int i = 0; i<n; i++) {
            ans = Math.min(ans, dp[i]);
        }

        return ans;
    }
}