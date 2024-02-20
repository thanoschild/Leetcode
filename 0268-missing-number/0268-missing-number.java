class Solution {
    public int missingNumber(int[] nums) {
        int i = 0, ans = 0;
        for(i = 0; i<nums.length; i++) ans = ans ^ i ^ nums[i];
        return ans ^ i;
    }
}