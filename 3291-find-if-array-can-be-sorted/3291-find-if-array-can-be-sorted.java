class Solution {
    public boolean canSortArray(int[] nums) {
        int n = nums.length, idx = 0;

        while(idx < n - 1) {
           int a = Integer.bitCount(nums[idx]);
           int b = Integer.bitCount(nums[idx+1]);

           if(nums[idx] > nums[idx+1] && a == b) {
              int temp = nums[idx];
              nums[idx] = nums[idx+1];
              nums[idx+1] = temp;
              idx = 0;
           } else if(nums[idx] <= nums[idx+1]) {
              idx++;
           } else if(nums[idx] > nums[idx+1] && a != b) {
             return false;
           }
        } 

        for(int i = 1; i<n; i++) {
            if(nums[i-1] > nums[i]) return false;
        }

        return true;
    }
}