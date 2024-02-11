class Solution {
public:
    int dir[3] = {-1, 0, 1};
    int dp[71][71][71];

    int solve(vector<vector<int>> &grid, int i, int j1, int j2, int n, int m) {
        if(i == n) return 0;
        if(j1 < 0 || j2 < 0 || j1 > m - 1 || j2 > m - 1) return -1e8;
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int ans = 0;
        for(int k = 0; k<3; k++) {
            for(int l = 0; l<3; l++) {
                ans = max(ans, solve(grid, i+1, j1 + dir[k], j2 + dir[l], n, m));
            }
        }
        ans += (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        return dp[i][j1][j2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, m-1, n, m);
    }
};