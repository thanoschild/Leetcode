class Solution {
    public boolean hasTrailingZeros(int[] nums) {
        int count = 0;
        for(int n : nums) {
            if(n % 2 == 0) count++;
        }

        return count >= 2;
    }
}