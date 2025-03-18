class Solution {
    public int longestNiceSubarray(int[] nums) {
        int ans = 0, curr = 0, i = 0, j = 0, n = nums.length;

        while(i < n && j < n) {
           if((curr & nums[i]) == 0) {
              ans = Math.max(ans, i - j + 1);
              curr |= nums[i];
              i++;
           } else {
               curr ^= nums[j];
               j++;
           }
        }

        return ans;
    }
}