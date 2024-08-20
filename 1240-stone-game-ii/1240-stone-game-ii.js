/**
 * @param {number[]} piles
 * @return {number}
 */
function solve(i, m, piles, dp) {
    if(i >= piles.length) return 0;
    if(dp[i][m] != -1) return dp[i][m];

    let ans = Number.MIN_SAFE_INTEGER, total = 0;
    for(let j = 0; j<2*m && i + j < piles.length; j++) {
        total += piles[i+j];
        ans = Math.max(ans, total - solve(i+j+1, Math.max(m, j+1), piles, dp));
    }
    dp[i][m] = ans;
    return ans;
}

var stoneGameII = function(piles) {
    const n = piles.length;
    const dp = Array.from({length : n+1}, () => Array(2*n + 1).fill(-1));

    let sum = 0;
    for(let it of piles) sum += it;
    let diff = solve(0, 1, piles, dp);
    return Math.floor((sum + diff)/2);
};