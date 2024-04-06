/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(mat) {
    const n = mat.length;
    const m = mat[0].length;
    let row = false;
    let col = false;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (mat[i][j] === 0) {
                if (i === 0) row = true;
                if (j === 0) col = true;
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }

    for (let i = 1; i < n; i++) {
        for (let j = 1; j < m; j++) {
            if (mat[i][0] === 0 || mat[0][j] === 0) mat[i][j] = 0;
        }
    }

    if (row) {
        for (let j = 0; j < m; j++) {
            mat[0][j] = 0;
        }
    }

    if (col) {
        for (let i = 0; i < n; i++) {
            mat[i][0] = 0;
        }
    }
};