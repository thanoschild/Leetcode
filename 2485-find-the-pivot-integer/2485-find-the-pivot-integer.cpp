class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1)/2;
        int x = sqrt(sum);
        return x * x == sum ? x : -1;
    }
};