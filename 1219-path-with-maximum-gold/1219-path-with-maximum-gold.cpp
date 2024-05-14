class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    int dfs(vector<vector<int>> &grid, int i, int j, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;
        int originalValue = grid[i][j];
        grid[i][j] = 0;

        int maxGold = 0;
        for(int k = 0; k<4; k++) {
            int x = i + dir[k], y = j + dir[k + 1];
            maxGold = max(maxGold, dfs(grid, x, y, n, m));
        }

        grid[i][j] = originalValue;
        return maxGold + originalValue;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans = max(ans, dfs(grid, i, j, n, m));
            }
        }

        return ans;
    }
};