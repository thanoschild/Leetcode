class Solution {
    int findPairs(int[] nums, int mid) {
        int count = 0;
        for(int i = 1; i<nums.length; i++) {
            if(nums[i] - nums[i-1] <= mid) {
                count++;
                i++;
            }
        }

        return count;
    }

    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int n = nums.length;
        int left = 0, right = nums[n-1] - nums[0], ans = 0;

        while(left <= right) {
            int mid = (right - left)/2 + left;
            int k = findPairs(nums, mid);
            if(k >= p) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
}