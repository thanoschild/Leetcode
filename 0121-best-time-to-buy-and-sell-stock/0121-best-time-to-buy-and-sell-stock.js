/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let profit = 0, least = prices[0];
    for(let price of prices) {
        least = Math.min(least, price);
        profit = Math.max(profit, price - least);
    }
    return profit;
};