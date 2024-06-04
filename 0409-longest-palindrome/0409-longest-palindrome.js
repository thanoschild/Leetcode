/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    const lower = new Array(26).fill(0);
    const upper = new Array(26).fill(0);

    for (let char of s) {
        if (char.toLowerCase() === char) {
        lower[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        } else {
        upper[char.charCodeAt(0) - 'A'.charCodeAt(0)]++;
        }
    }

    let result = 0;
    let hasOdd = 0;

    for (const count of lower.concat(upper)) {
        if (count % 2 === 0) {
        result += count;
        } else {
        result += count - 1;
        hasOdd = 1;
        }
    }

    return result + hasOdd;
};