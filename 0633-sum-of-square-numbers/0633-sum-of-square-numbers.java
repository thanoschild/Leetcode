class Solution {
    public boolean judgeSquareSum(int c) {
        for(long i = 0; i*i<=c; i++) {
            double a = Math.sqrt(c - i*i);
            if(a == (int)a) return true;
        }

        return false;
    }
}