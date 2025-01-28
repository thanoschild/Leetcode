class Solution {
public:
    int dirs[5] = {-1, 0, 1, 0, -1};
    int dfs(int i, int j, vector<vector<int>> &grid, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;
        int sum = grid[i][j];
        grid[i][j] = 0;
        
        for(int k = 0; k<4; k++) {
            sum += dfs(i + dirs[k], j + dirs[k+1], grid, n, m);
        }
        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans = max(ans, dfs(i, j, grid, n, m));
            }
        }

        return ans;
    }
};