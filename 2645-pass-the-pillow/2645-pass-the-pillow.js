/**
 * @param {number} n
 * @param {number} time
 * @return {number}
 */
var passThePillow = function(n, time) {
    time %= (n*2 - 2);
    return n - Math.abs(n - 1 - time);
};