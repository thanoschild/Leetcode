/**
 * @param {string} s
 * @return {number}
 */
var scoreOfString = function(s) {
    const n = s.length;
    let ans = 0;
    for (let i = 0; i < n - 1; i++) {
        let a = s.charCodeAt(i) - 'a'.charCodeAt(0);
        let b = s.charCodeAt(i + 1) - 'a'.charCodeAt(0);
        ans += Math.abs(a - b);
    }
    return ans;
};