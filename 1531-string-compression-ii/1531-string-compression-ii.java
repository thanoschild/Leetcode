class Solution {
    int[][] dp;

    int find(int x) {
        return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3;
    }

    int solve(String s, int start, int k, int n) {
        if(k < 0) return 127;
        if(start >= n || n - start <= k) return 0;
        if(dp[start][k] != -1) return dp[start][k];

        int ans = 127;
        int[] count = new int[26];
        for(int i = start, most = 0; i<n; i++) {
            most = Math.max(most, ++count[s.charAt(i) - 'a']);
            ans = Math.min(ans, 1 + find(most) + solve(s, i + 1, k - (i - start + 1 - most), n));
        }

        dp[start][k] = ans;
        return dp[start][k];
    }

    public int getLengthOfOptimalCompression(String s, int k) {
        dp = new int[127][127];
        for(int i = 0; i<127; i++) {
            Arrays.fill(dp[i], -1);
        }
        int n = s.length();
        return solve(s, 0, k, n);
    }
}