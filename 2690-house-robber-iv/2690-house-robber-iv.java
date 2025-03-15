class Solution {
    private boolean isValid(int[] nums, int mid, int k) {
        int count = 0;
        for(int i = 0; i<nums.length; i++) {
            if(nums[i] <= mid) {
                count++;
                i++;
            }
        }

        return count >= k;
    }

    public int minCapability(int[] nums, int k) {
        int left = 1, right = nums[0], ans = 0;
        for(int n : nums) right = Math.max(n, right);

        while(left <= right) {
            int mid = (right - left)/2 + left;
            if(isValid(nums, mid, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
}