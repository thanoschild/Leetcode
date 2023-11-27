class Solution {
    int mod = 1000000000 + 7;
    long findPath(int i, int j, int n, long[][][] dp) {
        if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1)) return 0;
        if(n == 1) return 1;
        if(dp[i][j][n] > 0) return dp[i][j][n];
        
        dp[i][j][n] = (findPath(i - 1, j - 2, n - 1, dp) % mod + 
                           findPath(i - 1, j + 2, n - 1, dp) % mod + 
                           findPath(i + 1, j - 2, n - 1, dp) % mod + 
                           findPath(i + 1, j + 2, n - 1, dp) % mod + 
                           findPath(i - 2, j - 1, n - 1, dp) % mod + 
                           findPath(i - 2, j + 1, n - 1, dp) % mod + 
                           findPath(i + 2, j - 1, n - 1, dp) % mod + 
                           findPath(i + 2, j + 1, n - 1, dp) % mod) % mod;
        
        return dp[i][j][n];
    }
    
    public int knightDialer(int n) {
        long ans = 0;
        long[][][] dp = new long[4][3][n+1];
        for(int i = 0; i<4; i++) {
            for(int j = 0; j<3; j++) {
                ans = (ans + findPath(i, j, n, dp)) % mod;
            }
        }
        
        return (int) ans;
    }
}