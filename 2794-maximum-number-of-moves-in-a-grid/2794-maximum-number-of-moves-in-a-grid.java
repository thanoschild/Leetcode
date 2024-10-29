class Solution {
    int[][] dirs = {{-1, 1}, {1, 1}, {0, 1}};

    private int dfs(int i, int j, int[][] grid, int[][] dp, int n, int m) {
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;

        for(int dir[] : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];

            if(x >= 0 && x < n && y >= 0 && y < m && grid[i][j] < grid[x][y]) {
                ans = Math.max(ans, 1 + dfs(x, y, grid, dp, n, m));
            }
        }

        return dp[i][j] = ans;
    } 

    public int maxMoves(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] dp = new int[n][m];
        Arrays.stream(dp).forEach(row -> Arrays.fill(row, -1));

        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans = Math.max(ans, dfs(i, 0, grid, dp, n, m));
        }

        return ans;
    }
}