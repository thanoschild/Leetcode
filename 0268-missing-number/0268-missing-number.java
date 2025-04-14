class Solution {
    public int missingNumber(int[] nums) {
        int _xor = 0, n = nums.length;
        for(int it : nums) _xor ^= it;
        for(int i = 0; i<=n; i++) _xor ^= i;

        return _xor;
    }
}