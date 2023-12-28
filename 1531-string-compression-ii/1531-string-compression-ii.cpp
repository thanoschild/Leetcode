class Solution {
public:
    int dp[127][127];

    int find(int x) {
        return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3;
    }

    int solve(string s, int start, int k, int n) {
        if(k < 0) return 127;
        if(start >= n or n - start <= k) return 0;
        if(dp[start][k] != -1) return dp[start][k];

        int count[26] = {0};
        int ans = 127;
        for(int i = start, most = 0; i<n; i++) {
            most = max(most, ++count[s[i]- 'a']);
            ans = min(ans, 1 + find(most) + solve(s, i + 1, k - (i - start + 1 - most), n));
        }

        return dp[start][k] = ans;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return solve(s, 0, k, n);
    }
};