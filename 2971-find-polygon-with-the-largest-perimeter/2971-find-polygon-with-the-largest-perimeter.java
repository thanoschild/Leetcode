class Solution {
    public long largestPerimeter(int[] nums) {
        int n = nums.length;
        long[] presum = new long[n];
        Arrays.sort(nums);
        long sum = 0;

        for(int i = 0; i<n; i++) {
            presum[i] = sum;
            sum += nums[i];
        }

        for(int i = n - 1; i>=2; i--) {
            if(nums[i] < presum[i]) {
                return presum[i] + nums[i];
            }
        }

        return -1;
    }
}