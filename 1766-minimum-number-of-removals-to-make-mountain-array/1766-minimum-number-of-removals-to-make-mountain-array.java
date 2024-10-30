class Solution {
    public int minimumMountainRemovals(int[] nums) {
        int n = nums.length;
        if(n < 2) return -1;
        int[] left = new int[n];
        Arrays.fill(left, 1);
        int[] right = new int[n];
        Arrays.fill(right, 1);

        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
               if(nums[i] > nums[j]) left[i] = Math.max(left[i], 1 + left[j]);
            }
        }

        for(int i = n - 2; i>=0; i--) {
            for(int j = n-1; j>i; j--) {
                if(nums[i] > nums[j]) right[i] = Math.max(right[i], 1 + right[j]);
            }
        }

        int maxLen = 0;
        for(int i = 1; i<n-1; i++) {
            if (left[i] > 1 && right[i] > 1) { 
               maxLen = Math.max(maxLen, left[i] + right[i] - 1);
            }
        }

        return n - maxLen;
    }
}