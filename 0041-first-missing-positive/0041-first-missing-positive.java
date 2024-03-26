class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        boolean[] seen = new boolean[n + 1];

        for(int val : nums) {
            if(val >= 0 && val <= n) {
                seen[val] = true;
            }
        }

        for(int i = 1; i<=n; i++) {
            if(seen[i] == false) return i;
        }

        return n + 1;
    }
}