class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] ans = new int[2];
        for(int n : nums) {
            if(nums[Math.abs(n) - 1] < 0) ans[0] = Math.abs(n);
            else nums[Math.abs(n) - 1] *= -1;
        }

        for(int i = 0; i<nums.length; i++) {
            if(nums[i] > 0) ans[1] = i + 1;
        }

        return ans;
    }
}