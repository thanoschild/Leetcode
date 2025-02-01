class Solution {
    public boolean isArraySpecial(int[] nums) {
        int n = nums.length;
        if(n == 1) return true;

        for(int i = 1; i<n; i++) {
            if(nums[i-1] % 2 == 0 && nums[i] % 2 == 0) return false;
            if(nums[i-1] % 2 == 1 && nums[i] % 2 == 1) return false;
        }

        return true;
    }
}