class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dp;
        dp = grid[n-1];

        for(int i = n - 2; i>=0; i--) {
            int firstMin = INT_MAX, secondMin = INT_MAX, idx = -1;
            for(int j = 0; j<n; j++) {
                if(firstMin > dp[j]) {
                    secondMin = firstMin;
                    firstMin = dp[j];
                    idx = j;
                }
                else if(secondMin > dp[j]) {
                    secondMin = dp[j];
                }
            }

            for(int j = 0; j<n; j++) {
                if(j == idx) dp[j] = grid[i][j] + secondMin;
                else dp[j] = grid[i][j] + firstMin;
            }
        }

        return *min_element(dp.begin(), dp.end());
    }
};