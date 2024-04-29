class Solution {
    public int minOperations(int[] nums, int k) {
        int _xor = 0;
       for(int num : nums) _xor ^= num;

       int count = 0;
       while(k > 0 || _xor > 0) {
           if((k % 2) != (_xor % 2)) count++;
           k /= 2;
           _xor /= 2;
       }

       return count;
    }
}