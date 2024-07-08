/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findTheWinner = function(n, k) {
    let ans = 0;
    for(let i = 1; i<=n; i++) {
        ans = (ans + k) % i;
    }

    return ans + 1;
};