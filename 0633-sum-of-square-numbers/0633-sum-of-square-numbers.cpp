class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long i = 0; i*i <=c; i++) {
            double a = sqrt(c - i*i);
            if(a == (int)a) return true;
        }
        return false;
    }
};