class Solution {
    Integer[][] dp;
    private int solve(int i, int m, int[] piles) {
        if(i >= piles.length) return 0;
        if(dp[i][m] != null) return dp[i][m];

        int ans = Integer.MIN_VALUE, total = 0;
        for(int j = 0; j<2*m && i + j < piles.length; j++) {
            total += piles[i+j];
            ans = Math.max(ans, total - solve(i+j+1, Math.max(m, j+1), piles));
        }
        dp[i][m] = ans;
        return ans;
    }

    public int stoneGameII(int[] piles) {
        int n = piles.length;
        dp = new Integer[n+1][2*n + 1];
        int sum = 0;
        for(int it : piles) sum += it;
        int diff = solve(0, 1, piles);
        return (sum + diff)/2;
    }
}