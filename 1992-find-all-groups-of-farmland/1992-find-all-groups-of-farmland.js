/**
 * @param {number[][]} land
 * @return {number[][]}
 */
function dfs(grid, i, j, n, m, curr) {
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return;

    grid[i][j] = 0;
    curr[2] = Math.max(curr[2], i);
    curr[3] = Math.max(curr[3], j);
    dir = [-1, 0, 1, 0, -1];
    for(let k = 0; k<4; k++) {
        let x = dir[k] + i;
        let y = dir[k + 1] + j;
        dfs(grid, x, y, n, m, curr);
    }
}

var findFarmland = function(grid) {
    const ans = []
    const n = grid.length;
    const m = grid[0].length;

    for(let i = 0; i<n; i++) {
        for(let j = 0; j<m; j++) {
            if(grid[i][j] == 1) {
                curr = new Array(4).fill(0);
                curr[0] = curr[2] = i;
                curr[1] = curr[3] = j;
                dfs(grid, i, j, n, m, curr);
                ans.push(curr);
            }
        }
    }

    return ans;
};