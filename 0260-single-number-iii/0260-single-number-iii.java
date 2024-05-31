class Solution {
    public int[] singleNumber(int[] nums) {
        int n = nums.length;
        long _xor = 0;
        for(int i = 0; i<n; i++) _xor ^= nums[i];

        long rightBit = _xor & (-_xor);
        int x = 0, y = 0;

        for(int i = 0; i<n; i++) {
            if((rightBit & nums[i]) == 0) x ^= nums[i];
            else y ^= nums[i];
        }

        return new int[]{x, y};
    }
}