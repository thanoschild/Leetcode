/**
 * @param {character[][]} grid
 * @return {number}
 */

dir = [-1, 0, 1, 0, -1];

function dfs(grid, i, j, n, m) {
   if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        for(let k = 0; k<4; k++) {
            let x = i + dir[k];
            let y = j + dir[k + 1];
            dfs(grid, x, y, n, m);
        }
};

var numIslands = function(grid) {
    let n = grid.length;
    let m = grid[0].length;
    let ans = 0;

    for(let i = 0; i<n; i++) {
        for(let j = 0; j<m; j++) {
            if(grid[i][j] == '1') {
                dfs(grid, i, j, n, m);
                ans++;
            }
        }
    }

    return ans;
};