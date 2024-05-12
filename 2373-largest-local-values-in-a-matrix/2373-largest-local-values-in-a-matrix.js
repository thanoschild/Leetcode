/**
 * @param {number[][]} grid
 * @return {number[][]}
 */
var largestLocal = function(grid) {
    const n = grid.length;
    const ans = Array.from({length : n - 2}, () => Array(n - 2).fill(0));

    for(let i = 0; i<n-2; i++) {
        for(let j = 0; j<n-2; j++) {
            let val = Number.MIN_SAFE_INTEGER;
            for(let x = i; x<i+3; x++) {
                for(let y = j; y<j + 3; y++) {
                    val = Math.max(val, grid[x][y]);
                }
            }
            ans[i][j] = val;
        }
    }

    return ans;
};