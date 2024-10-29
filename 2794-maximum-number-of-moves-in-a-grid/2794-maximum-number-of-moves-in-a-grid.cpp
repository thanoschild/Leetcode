class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<vector<int>> dirs = {{0, 1}, {-1, 1}, {1, 1}};

        function<int(int, int)> dfs = [&](int i, int j) {
            if(dp[i][j] != -1) return dp[i][j];
            int ans = 0;
            for(auto dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if(x >= 0 && x < n && y >= 0 && y < m && grid[i][j] < grid[x][y]) {
                    ans = max(ans, 1 + dfs(x, y));
                }
            } 
            return dp[i][j] = ans;
        };
     
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans = max(ans, dfs(i, 0));
        }

        return ans;
    }
};