/**
 * @param {number[][]} grid
 * @return {number}
 */
const dir = [-1, 0, 1, 0, -1];

function dfs(grid, i, j, n, m) {
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;
    let val = grid[i][j];
    grid[i][j] = 0;

    let maxGold = 0;
    for(let k = 0; k<4; k++) {
        let x = i + dir[k], y = j + dir[k + 1];
        maxGold = Math.max(maxGold, dfs(grid, x, y, n, m));
    }

    grid[i][j] = val;
    return maxGold + val;
};

var getMaximumGold = function(grid) {
    let n = grid.length, m = grid[0].length;
    let ans = 0;

    for(let i = 0; i<n; i++) {
        for(let j = 0; j<m; j++) {
            ans = Math.max(ans, dfs(grid, i, j, n, m));
        }
    }

    return ans;
};