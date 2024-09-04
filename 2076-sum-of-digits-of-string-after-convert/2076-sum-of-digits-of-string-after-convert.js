/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */

function  sumDigit(num) {
    let ans = 0;
    while (num > 0) {
        ans += num % 10;
        num = Math.floor(num / 10);
    }
    return ans;
}

var getLucky = function(s, k) {
    let totalSum = 0;

    for (let c of s) {
        let value = c.charCodeAt(0) - 'a'.charCodeAt(0) + 1;
        while (value > 0) {
            totalSum += value % 10;
            value = Math.floor(value / 10);
        }
    }

    while (k > 1) {
        totalSum = sumDigit(totalSum);
        k--;
    }

    return totalSum;
};