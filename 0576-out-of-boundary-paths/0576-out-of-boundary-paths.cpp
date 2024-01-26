class Solution {
public:
    int dp[51][51][52];
    int v[5] = {-1, 0, 1, 0, -1};
    const int mod = 1e9 + 7;

    int solve(int &n, int &m, int move, int i, int j) {
        if(i<0 || i == n || j < 0 || j==m) return 1;
        if(move == 0) return 0;

        if(dp[i][j][move] != -1) return dp[i][j][move];
        int count = 0;

        for(int k = 0; k<4; k++) {
            int x = i + v[k];
            int y = j + v[k+1];
            count = (count + solve(n, m, move - 1, x, y)) % mod;
        }

        return dp[i][j][move] = count;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};