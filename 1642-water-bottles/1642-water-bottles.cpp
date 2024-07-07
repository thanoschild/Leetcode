class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange) {
            int rem = numBottles % numExchange;
            numBottles /= numExchange;
            ans += numBottles;
            numBottles += rem;
        }

        return ans;
    }
};