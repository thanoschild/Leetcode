class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length, ans = 0;
        int currWindowFlips = 0;

        for(int i = 0; i<n; i++) {
            if(i - k >= 0 && nums[i - k] == 2) currWindowFlips--;

            if((nums[i] + currWindowFlips) % 2 == 0) {
                if(i+k > n) return -1;
                ans++;
                currWindowFlips++;
                nums[i] = 2;
            }
        }

        return ans;
    }
}