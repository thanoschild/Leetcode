class Solution {
    int[] dir = {-1, 0, 1};
    public int solve(int[][] grid, int i, int j1, int j2, int n, int m, Integer[][][] dp) {
        if(i == n) return 0;
        if(j1 < 0 || j2 < 0 || j1 > m - 1 || j2 > m - 1) return (int) -1e8;
        if(dp[i][j1][j2] != null) return dp[i][j1][j2];

        int ans = 0;
        for(int k = 0; k<3; k++) {
            for(int l = 0; l<3; l++) {
                ans = Math.max(ans, solve(grid, i+1, j1 + dir[k], j2 + dir[l], n, m, dp));
            }
        }
        ans += (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        dp[i][j1][j2] = ans;
        return dp[i][j1][j2];
    }

    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        if(n == 0) return 0;
        int m = grid[0].length;
        Integer[][][] dp = new Integer[n+1][m+1][m+1];
        return solve(grid, 0, 0, m-1, n, m, dp);
    }
}