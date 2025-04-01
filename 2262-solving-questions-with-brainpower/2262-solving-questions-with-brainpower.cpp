#define ll long long
class Solution {
public:
    long long mostPoints(vector<vector<int>>& qn) {
        int n = qn.size();
        vector<ll> dp(n, -1);

        function<ll(int)> solve = [&](int idx) {
            if(idx >= n) return (ll) 0;
            if(dp[idx] != -1) return dp[idx];
            ll ans1 = solve(qn[idx][1] + idx + 1) + 1L * qn[idx][0];
            ll ans2 = solve(idx + 1);
            dp[idx] = max(ans1, ans2);
            return dp[idx];
        };

        return solve(0);
    }
};