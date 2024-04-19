class Solution {
    int dir[] = {-1, 0, 1, 0, -1};

    private void dfs(char[][] grid, int i, int j, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        for(int k = 0; k<4; k++) {
            int x = i + dir[k];
            int y = j + dir[k + 1];
            dfs(grid, x, y, n, m);
        }
    }
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int ans = 0;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    ans++;
                }
            }
        }

        return ans;
    }
}