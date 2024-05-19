class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        int n = nums.length;
        Integer[] delta = new Integer[n];
        for(int i = 0; i<n; i++) {
            delta[i] = (nums[i] ^ k) - nums[i];
        }

        long ans = 0;
        for(int num : nums) ans += num;
        Arrays.sort(delta, (a, b) -> b - a);

        for(int i = 0; i<n; i+=2) {
            if(i == n - 1) break;
            int curr_delta = delta[i] + delta[i+1];
            if(curr_delta <= 0) break;
            ans += curr_delta;
        }

        return ans;
    }
}