/**
 * @param {string} ring
 * @param {string} key
 * @return {number}
 */
var findRotateSteps = function(ring, key) {
    const n = ring.length, m = key.length;
    let dp = Array.from({length : (m + 1)}, () => Array(n).fill(0));

    for(let i = m - 1; i>=0; i--) {
        for(let j = 0; j<n; j++) {
            dp[i][j] = Number.MAX_SAFE_INTEGER;
            for(let k = 0; k<n; k++) {
                if(ring[k] === key[i]) {
                    let diff = Math.abs(k - j);
                    let step = Math.min(diff, n - diff);
                    dp[i][j] = Math.min(dp[i][j], step + dp[i+1][k]);
                }
            }
        }
    }

    return dp[0][0] + m;
};