class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        HashMap<Long, Integer>[] dp = new HashMap[n];
        int ans = 0;
        for(int i = 0; i<n; i++) {
            dp[i] = new HashMap<>();
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                long diff = (long) nums[i] - nums[j];
                int count = dp[j].containsKey(diff) ? dp[j].get(diff) : 0;
                dp[i].put(diff, dp[i].getOrDefault(diff, 0) + count + 1);
                ans += count;
            }
        }

        return ans;
    }
}