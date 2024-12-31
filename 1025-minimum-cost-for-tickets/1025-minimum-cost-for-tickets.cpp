class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(days[n-1] + 1, -1);
        unordered_set<int> mp(days.begin(), days.end());

        function<int(int)> solve = [&](int curr) -> int {
            if(curr > days[n-1]) return 0;
            if(dp[curr] != -1) return dp[curr];

            int ans = INT_MAX;
            if(mp.count(curr)) {
                ans = solve(curr + 1) + costs[0];
                ans = min(ans, solve(curr + 7) + costs[1]);
                ans = min(ans, solve(curr + 30) + costs[2]);
            } else {
                ans = solve(curr + 1);
            }

            dp[curr] = ans;
            return dp[curr];
        };

        return solve(days[0]);
    }
};