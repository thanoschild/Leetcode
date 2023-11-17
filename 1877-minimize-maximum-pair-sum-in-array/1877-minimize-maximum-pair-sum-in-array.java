class Solution {
    public int minPairSum(int[] nums) {
        int ans1 = Integer.MIN_VALUE, ans2 = Integer.MIN_VALUE, n = nums.length;
        Arrays.sort(nums);
        for(int i = 0; i<n/2; i++) {
            ans1 = Math.max(ans1, nums[i] + nums[n - i - 1]);
            ans2 = Math.max(ans2, nums[i] + nums[n/2 + i]);
        }
        return Math.min(ans1, ans2);
    }
}