class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0, least = prices[0];
        for(int i = 1; i<prices.length; i++){
            least = Math.min(least, prices[i]);
            profit = Math.max(profit, prices[i] - least);
        }
        return profit;
    }
}