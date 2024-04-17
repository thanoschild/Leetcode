/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(mat) {
    const n = mat.length;
    for(let i = 0; i<n; i++) {
        for(let j = i; j<n; j++) {
            let temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    for(let i = 0; i<n; i++) {
        mat[i] = [...mat[i]].reverse();
    }
};