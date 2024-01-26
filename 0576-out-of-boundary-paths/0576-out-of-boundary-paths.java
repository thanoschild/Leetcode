class Solution {
    int[] dir = {-1, 0, 1, 0, -1};
    final int mod = (int) 1e9 + 7;

    int solve(int n, int m, int move, int i, int j, int[][][] dp) {
        if(i < 0 || i == n || j < 0 || j == m) return 1;
        if(move == 0) return 0;
        if(dp[i][j][move] != -1) return dp[i][j][move];

        int count = 0;
        for(int k = 0; k<4; k++) {
            int x = i + dir[k];
            int y = j + dir[k+1];
            count = (count + solve(n, m, move - 1, x, y, dp)) % mod;
        }

        dp[i][j][move] = count;
        return dp[i][j][move];
    }

    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int[][][] dp = new int[m+1][n+1][maxMove + 1];
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
}