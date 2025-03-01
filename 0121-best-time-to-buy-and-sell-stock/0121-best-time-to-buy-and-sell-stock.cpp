class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minVal = prices[0];
        for(int it : prices) {
            ans = max(ans, it - minVal);
            minVal = min(minVal, it);
        }

        return ans;
    }
};