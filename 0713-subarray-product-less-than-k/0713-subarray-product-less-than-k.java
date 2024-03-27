class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int n = nums.length;
        int count = 0, pro = 1;

        for(int i = 0, j = 0; j<n; j++) {
            pro *= nums[j];
            while(i <= j && pro >= k) {
                pro /= nums[i];
                i++;
            }
            count += (j - i + 1);
        }

        return count;
    }
}