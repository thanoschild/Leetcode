/**
 * @param {number[][]} grid
 * @return {number}
 */
var minFallingPathSum = function(grid) {
    const n = grid.length;
    let dp = grid[n-1];

    for(let i = n - 2; i>=0; i--) {
        let firstMin = Number.MAX_SAFE_INTEGER;
        let secondMin = Number.MAX_SAFE_INTEGER;
        let idx = -1;
        for(let j = 0; j<n; j++) {
            if(firstMin > dp[j]) {
                secondMin = firstMin;
                firstMin = dp[j];
                idx = j;
            }
            else if(secondMin > dp[j]) {
                secondMin = dp[j];
            }
        }

        for(let j = 0; j<n; j++) {
            if(j == idx) dp[j] = grid[i][j] + secondMin;
            else dp[j] = grid[i][j] + firstMin;
        }
    }

    return Math.min(...dp);
};