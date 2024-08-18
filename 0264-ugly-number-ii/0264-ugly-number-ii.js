/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    let k2 = 0, k3 = 0, k5 = 0;
    const dp = new Array(n+1).fill(0);
    dp[0] = 1;

    for(let i = 1; i<=n; i++) {
        dp[i] = Math.min(2*dp[k2], Math.min(3*dp[k3], 5*dp[k5]));
        if(dp[i] == 2*dp[k2]) k2++;
        if(dp[i] == 3*dp[k3]) k3++;
        if(dp[i] == 5*dp[k5]) k5++;
    }

    return dp[n-1];
};