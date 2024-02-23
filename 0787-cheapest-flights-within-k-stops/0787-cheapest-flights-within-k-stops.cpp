class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2, vector<int>(n, 1e8));
        for(int i = 0; i<k+2; i++) {
            dp[i][src] = 0;
        }

        for(int i = 1; i<k+2; i++) {
            for(auto it : flights) {
                int u = it[0], v = it[1], w = it[2];
                if(dp[i-1][u] != 1e8) {
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
                }
            }
        }

        return dp[k+1][dst] == 1e8 ? -1 : dp[k+1][dst];
    }
};