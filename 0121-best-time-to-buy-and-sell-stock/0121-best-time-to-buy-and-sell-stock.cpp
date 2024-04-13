class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, least = prices[0];
        for(int price : prices) {
            least = min(least, price);
            profit = max(profit, price - least);
        }
        return profit;
    }
};