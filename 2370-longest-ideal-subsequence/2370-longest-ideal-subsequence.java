class Solution {
    public int longestIdealString(String s, int k) {
        int[] dp = new int[26];
        int ans = 0;

        for(char c : s.toCharArray()) {
            int i = c - 'a';
            dp[i] += 1;
            for(int j = Math.max(0, i - k); j<= Math.min(25, i + k); j++) {
                if(i != j) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            ans = Math.max(ans, dp[i]);
        }

        return ans;
    }
}