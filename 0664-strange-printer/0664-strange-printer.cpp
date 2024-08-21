class Solution {
public:
    int dp[100][100];
    int solve(string s, int i, int j) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = solve(s, i, j - 1) + 1;
        for(int k = i; k<j; k++) {
            if(s[k] == s[j]) {
                ans = min(ans, solve(s, i, k-1) + solve(s, k, j-1));
            }
        }
        return dp[i][j] = ans;
    }

    int strangePrinter(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return n;
        string str = "";
        str += s[0];
        for(int i = 1; i<n; i++) {
            if(s[i] == s[i-1]) continue;
            else str += s[i];
        }
        cout<<str<<endl;
        memset(dp, -1, sizeof(dp));
        return solve(str, 0, str.size() - 1);
    }
};