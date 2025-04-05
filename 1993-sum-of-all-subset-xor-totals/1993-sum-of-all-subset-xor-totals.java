class Solution {
    public int subsetXORSum(int[] nums) {
        int n = nums.length, ans = 0;

        for(int i = 0; i<(1 << n); i++) {
            int _xor = 0;
            for(int j = 0; j<n; j++) {
                if((i & (1 << j)) >= 1) {
                    _xor ^= nums[j];
                }
            }
            ans += _xor;
        }

        return ans;
    }
}