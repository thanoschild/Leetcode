class Solution {
    public int specialArray(int[] nums) {
        int n = nums.length;
        int[] count = new int[n+1];

        for(int num : nums) {
            if(num >= n) count[n]++;
            else count[num]++;
        }

        int ans = 0;
        for(int i = n; i>0; i--) {
            ans += count[i];
            if(ans == i) return i;
        }

        return -1;
    }
}