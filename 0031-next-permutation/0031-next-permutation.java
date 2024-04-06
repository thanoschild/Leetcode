class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        boolean flag = true;

        for(int i = n - 2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                flag = false;
                Arrays.sort(nums, i+1, n);
                int k = i+1;
                while(nums[i] >= nums[k]) k++;
                int temp = nums[i];
                nums[i] = nums[k];
                nums[k] = temp;
                break;
            }
        }

        if(flag) Arrays.sort(nums);
    }
}