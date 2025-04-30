class Solution {
    public int findNumbers(int[] nums) {
        int ans = 0;
        for(int n : nums) {
            int count = 0, x = n;
            while(x > 0) {
                count++;
                x /= 10;
            }
            if((count & 1) == 0) ans++;
        }

        return ans;
    }
}