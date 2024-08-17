class Solution {
public:
    long long maxPoints(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));

        for(int j = 0; j<m; j++) dp[0][j] = arr[0][j];

        for(int i = 1; i<n; i++) {
            vector<long long> left_dp(m, -1);
            vector<long long> right_dp(m, -1);

            left_dp[0] = dp[i-1][0];
            for(int j = 1; j<m; j++) {
                left_dp[j] = max(left_dp[j-1], dp[i-1][j] + j);
            }

            right_dp[m-1] = dp[i-1][m-1] - (m-1);
            for(int j = m - 2; j>=0; j--) {
                right_dp[j] = max(right_dp[j+1], dp[i-1][j] - j);
            }

            for(int j = 0; j<m; j++) {
                dp[i][j] = max(left_dp[j] - j, right_dp[j] + j) + arr[i][j];
            }
        }

        long long ans = -1;
        for(auto it : dp[n-1]) {
            ans = max(ans, it);
        }

        return ans;
    }
};