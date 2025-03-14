class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (s1[i - 1] == s2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }

        int i = m, j = n;
        string scs = "";

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                scs += s1[i - 1];
                i--, j--;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                scs += s1[i - 1];
                i--;
            } else {
                scs += s2[j - 1];
                j--;
            }
        }

        while (i > 0) scs += s1[--i];
        while (j > 0) scs += s2[--j];

        reverse(scs.begin(), scs.end());
        return scs;
    }
};