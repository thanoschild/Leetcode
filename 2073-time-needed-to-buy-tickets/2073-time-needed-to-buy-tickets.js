/**
 * @param {number[]} tickets
 * @param {number} k
 * @return {number}
 */
var timeRequiredToBuy = function(tickets, k) {
    let ans = 0, n = tickets.length;
    for(let i = 0; i<n; i++) {
        let val = i > k ? tickets[k] - 1 : tickets[k];
        ans += Math.min(val, tickets[i]);
    }

    return ans;
};