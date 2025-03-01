class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(n == 0) return 0;
        int ans = 0, minPrice = prices[0];
        
        for(int it : prices) {
            ans = Math.max(ans, it - minPrice);
            minPrice = Math.min(minPrice, it);
        }
        
        return ans;
    }
}