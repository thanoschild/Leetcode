class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, need = 0;
        for(int n : nums) {
            ans += Math.max(need - n, 0);
            need = Math.max(n, need) + 1;
        }

        return ans;
    }
}