/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestIdealString = function(s, k) {
    const dp = new Array(26).fill(0);
    let ans = 0;

    for(let c of s) {
        let i = c.charCodeAt(0) - 'a'.charCodeAt(0);
        dp[i] += 1;
        for(let j = Math.max(0, i - k); j <= Math.min(25, i + k); j++) {
            if(i !== j) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
            ans = Math.max(ans, dp[i]);
        }
    }

    return ans;
};