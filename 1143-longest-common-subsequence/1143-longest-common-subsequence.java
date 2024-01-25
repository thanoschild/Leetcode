class Solution {

    int lcs(String s1, String s2, int i, int j, int[][] dp) {
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1.charAt(i-1) == s2.charAt(j-1)) {
            dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1, dp);
            return dp[i][j];
        }
        else {
            dp[i][j] = Math.max(lcs(s1, s2, i - 1, j, dp), lcs(s1, s2, i, j - 1, dp));
            return dp[i][j];
        }
    }
    
    public int longestCommonSubsequence(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        int[][] dp = new int[n+1][m+1];
        for(int i = 0; i<n+1; i++) {
            for(int j = 0; j<m+1; j++) {
                dp[i][j] = -1;
            }
        }

        return lcs(s1, s2, n, m, dp);
    }
}