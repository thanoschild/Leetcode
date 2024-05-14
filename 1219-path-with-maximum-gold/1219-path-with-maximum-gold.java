class Solution {
    int[] dir = {-1, 0, 1, 0, -1};
    private int solve(int[][] grid, int i, int j, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;
        int gold = grid[i][j];
        grid[i][j] = 0;
        int maxgold = 0;

        for(int k = 0; k<4; k++) {
            int x = dir[k] + i;
            int y = dir[k + 1] + j;
            maxgold = Math.max(maxgold, solve(grid, x, y, n, m));
        }
         
        grid[i][j] = gold;
        return maxgold + gold;
    }

    public int getMaximumGold(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int ans = 0;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans = Math.max(ans, solve(grid, i, j, n, m));
            }
        }

        return ans;
    }
}