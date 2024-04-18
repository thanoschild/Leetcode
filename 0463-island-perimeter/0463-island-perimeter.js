/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    const n = grid.length, m = grid[0].length;
    let ans = 0;

    for(let i = 0; i<n; i++) {
        for(let j = 0; j<m; j++) {
            if(grid[i][j] == 1) {
                ans += 4;
                if(i > 0 && grid[i-1][j] == 1) ans -= 2;
                if(j > 0 && grid[i][j-1] == 1) ans -= 2; 
            }
        }
    }

    return ans;
};