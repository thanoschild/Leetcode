class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int it : nums) sum += it;

        if(sum % 2 == 1) return false;
        sum = sum / 2;
        boolean[] dp = new boolean[sum + 1];
        dp[0] = true;

        for(int it : nums) {
            for(int i = sum; i>0; i--) {
                if(i >= it && dp[i - it]) dp[i] = true;
            }
        }

        return dp[sum];
    }
}