/**
 * @param {number[][]} customers
 * @return {number}
 */
var averageWaitingTime = function(customers) {
    let ans = 0.0, curr = 0.0;
    for(let c of customers) {
        curr = Math.max(curr, 1.0 * c[0]) + c[1];
        ans += curr - c[0];
    }

    return 1.0 * ans / customers.length;
};