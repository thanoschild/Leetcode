/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function(numBottles, numExchange) {
    let ans = numBottles;
    while(numBottles >= numExchange) {
        let rem = numBottles % numExchange;
        numBottles = Math.floor(numBottles / numExchange);
        ans += numBottles;
        numBottles += rem;
    }

    return ans;
};