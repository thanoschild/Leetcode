class Solution {
    public int maximalRectangle(char[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[][] dp = new int[n][m];

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(i == 0) dp[i][j] = mat[i][j] - '0';
                else {
                    if(mat[i][j] == '0') dp[i][j] = 0;
                    else dp[i][j] = dp[i-1][j] + 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++) {
            Stack<Integer> st = new Stack<>();
            for(int j = 0; j<=m; j++) {
                int curr = j == m ? 0 : dp[i][j];
                while(!st.isEmpty() && dp[i][st.peek()] > curr) {
                    int h = dp[i][st.pop()];
                    int l = st.isEmpty() ? j : j - st.peek() - 1;
                    ans = Math.max(ans, l*h);
                }
                st.add(j);
            }
        }

        return ans;
    }
}