class Solution {
    public int minBitFlips(int start, int goal) {
        int _xor = start ^ goal, count = 0;
        for(int i = 0; i<32; i++) {
            if((_xor & (1 << i)) >= 1) count++; 
        }

        return count;
    }
}