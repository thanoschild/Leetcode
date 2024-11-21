class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        for (auto& e : guards)
            dp[e[0]][e[1]] = 2;
        for (auto& e : walls)
            dp[e[0]][e[1]] = 2;

        int dirs[5] = {-1, 0, 1, 0, -1};

        for (auto& e : guards) {
            for (int k = 0; k < 4; k++) {
                int x = e[0];
                int y = e[1];

                while (true) {
                    x += dirs[k];
                    y += dirs[k + 1];
                    if (x < 0 || x >= m || y < 0 || y >= n || dp[x][y] == 2) {
                        break;
                    }
                    if (dp[x][y] == 0) {
                        dp[x][y] = 1;
                    }
                }
            }
        }

        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            unguardedCount += count(dp[i], dp[i] + n, 0);
        }

        return unguardedCount;
    }
};