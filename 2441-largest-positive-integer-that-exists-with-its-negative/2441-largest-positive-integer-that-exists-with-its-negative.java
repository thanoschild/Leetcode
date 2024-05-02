class Solution {
    public int findMaxK(int[] nums) {
        Arrays.sort(nums);
        int i = 0, j = nums.length - 1;

        while(i < j && nums[i] < 0 && nums[j] > 0) {
            if(Math.abs(nums[i]) == nums[j]) return nums[j];
            if(Math.abs(nums[i]) > nums[j]) i++;
            else j--;
        }

        return -1;
    }
}