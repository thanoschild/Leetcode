class Solution {
    private void swap(int[] nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }

    public void sortColors(int[] nums) {
        int left = 0, mid = 0, right = nums.length - 1;
        while(mid <= right) {
            if(nums[mid] == 0) {
                swap(nums, left, mid);
                left++; mid++;
            }
            else if(nums[mid] == 1) mid++;
            else {
                swap(nums, mid, right);
                right--;
            }
        }
    }
}