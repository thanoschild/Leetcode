class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    int dfs(vector<vector<int>> &grid, int i, int j, int &ans, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 1;
        if(grid[i][j] == -1) return 0;

        grid[i][j] = -1;
        for(int k = 0; k<4; k++) {
            int x = dir[k] + i;
            int y = dir[k + 1] + j;
            ans += dfs(grid, x, y, ans, n, m);
        }

        return 0;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, ans, n, m);
                    break;
                }
            }
        }

        return ans;
    }
};