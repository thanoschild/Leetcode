import java.util.Arrays;

class Solution {
        private int lowerBound(int[] nums, int start, int end, int target) {
        int low = start, high = end;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    private int upperBound(int[] nums, int start, int end, int target) {
        int low = start, high = end;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    
    public long countFairPairs(int[] nums, int lower, int upper) {
        int n = nums.length;
        if(n < 2) return 0;
        Arrays.sort(nums);
        
        long ans = 0;
        for(int i = 0; i<n-1; i++) {
            int x = lower - nums[i];
            int y = upper - nums[i];
            int a = lowerBound(nums, i + 1, n, x);
            int b = upperBound(nums, i + 1, n, y);
            ans += (b - a);
        }

        return ans;
    }
}