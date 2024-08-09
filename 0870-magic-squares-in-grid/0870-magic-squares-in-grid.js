/**
 * @param {number[][]} grid
 * @return {number}
 */
function checkGrid(i, j, grid) {
    let counts = new Array(10).fill(0); // Array to track counts of numbers 1-9

    for (let k = i; k < i + 3; k++) {
        let sumRows = 0;
        for (let l = j; l < j + 3; l++) {
            sumRows += grid[k][l];
            if (grid[k][l] < 1 || grid[k][l] > 9) return false;
            counts[grid[k][l]]++;
        }
        if (sumRows !== 15) return false;
    }

    for (let k = j; k < j + 3; k++) {
        let sumCols = 0;
        for (let l = i; l < i + 3; l++) {
            sumCols += grid[l][k];
        }
        if (sumCols !== 15) return false;
    }

    let leftd = 0, rightd = 0;
    for (let k = 0; k < 3; k++) {
        leftd += grid[i + k][j + k];
        rightd += grid[i + k][j + 2 - k];
    }

    if (leftd !== 15 || rightd !== 15) return false;

    for (let k = 1; k <= 9; k++) {
        if (counts[k] !== 1) return false;
    }

    return true;
}

var numMagicSquaresInside = function(grid) {
    let n = grid.length, m = grid[0].length;
    if (n < 3 || m < 3) return 0;
    let ans = 0;

    for (let i = 0; i <= n - 3; i++) {
        for (let j = 0; j <= m - 3; j++) {
            if (checkGrid(i, j, grid)) ans++;
        }
    }

    return ans;
};
