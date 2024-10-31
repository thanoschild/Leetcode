class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size(), m = factory.size();
        long long dp[n][m][101];
        memset(dp, -1, sizeof(dp));
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        function<long long(int, int, int)> solve = [&](int i, int j, int k) {
           if(i == n) return (long long) 0;
           if(j == m) return (long long) 1e16;
           if(dp[i][j][k] != -1) return dp[i][j][k];

           long long ans1 = solve(i, j+1, 0);
           long long ans2 = (k < factory[j][1]) ? solve(i+1, j, k+1) + abs(robot[i] - factory[j][0]) : 1e16;
           dp[i][j][k] = min(ans1, ans2);
           return dp[i][j][k];
        };

        return solve(0, 0, 0);
    }
};