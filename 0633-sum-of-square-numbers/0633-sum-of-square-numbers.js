/**
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function(c) {
    for (let i = 0; i * i <= c; i++) {
        let a = Math.sqrt(c - i * i);
        if (a === Math.floor(a)) return true;
    }
    return false;
};