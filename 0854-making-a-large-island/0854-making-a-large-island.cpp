class Solution {
public:
    int dfs(int i, int j, int check, vector<vector<int>> &grid, bool flip = false) {
        if(!flip && (min(i, j) < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == check)) return 0;

        grid[i][j] = grid[i][j] == 0 ? 0 : check;
        return 1 + dfs(i+1, j, check, grid) + dfs(i-1, j, check, grid) + dfs(i, j+1, check, grid) + dfs(i, j-1, check, grid);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 0) {
                    ans = max(ans, dfs(i, j, 2, grid, true));
                    dfs(i, j, 1, grid, true);
                }
            }
        }

        return ans == 0 ? n * m : ans;
    }
};