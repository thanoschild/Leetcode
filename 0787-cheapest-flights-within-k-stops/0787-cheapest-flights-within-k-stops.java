class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        Integer[][] dp = new Integer[k+2][n];
        for(int i = 0; i<k+2; i++) {
            dp[i][src] = 0;
        }

        for(int i = 1; i<k+2; i++) {
            for(int[] it : flights) {
                int u = it[0], v = it[1], w = it[2];
                if(dp[i-1][u] != null) {
                    if(dp[i][v] == null) dp[i][v] = (int) 1e9;
                    dp[i][v] = Math.min(dp[i][v], dp[i-1][u] + w);
                }
            }
        }

        return dp[k+1][dst] == null ? -1 : dp[k+1][dst];
    }
}