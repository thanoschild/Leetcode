class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        if(nums[l] <= nums[r]) return nums[l];

        while(l <= r) {
            int mid = (r - l)/2 + l;
            if(nums[mid] > nums[mid + 1]) return nums[mid+1];
            else if(nums[mid] < nums[mid - 1]) return nums[mid];
            else if(nums[l] <= nums[mid]) l = mid + 1;
            else if(nums[mid] <= nums[r]) r = mid - 1;
        }

        return -1;
    }
}