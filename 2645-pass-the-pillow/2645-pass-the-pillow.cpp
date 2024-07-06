class Solution {
public:
    int passThePillow(int n, int time) {
        time %= (n*2 - 2);
        return n - abs(n - 1 - time);
    }
};