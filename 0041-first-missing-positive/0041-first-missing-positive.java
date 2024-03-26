class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        boolean containOne = false;
        for(int val : nums) {
            if(val == 1) {
                containOne = true;
            }
        }

        if(!containOne) return 1;
        if(n == 1 && containOne) return 2;

        for(int i = 0; i<n; i++) {
            if(nums[i] <= 0 || nums[i] > n) {
               nums[i] = 1;
            }
        }

        for(int i = 0; i<n; i++) {
            int idx = Math.abs(nums[i]) - 1;
            if(nums[idx] > 0) nums[idx] *= -1;
        }

        for(int i = 0; i<n; i++) {
            if(nums[i] > 0) return i + 1;
        }

        return n + 1;
    }
}