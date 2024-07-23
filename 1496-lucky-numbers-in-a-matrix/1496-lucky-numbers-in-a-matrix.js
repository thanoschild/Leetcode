/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers  = function(mat) {
    const n = mat.length;
    const m = mat[0].length;
    const minRow = new Array(n).fill(Infinity);
    const maxCol = new Array(m).fill(-Infinity);

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            minRow[i] = Math.min(minRow[i], mat[i][j]);
            maxCol[j] = Math.max(maxCol[j], mat[i][j]);
        }
    }

    const ans = [];
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (minRow[i] === maxCol[j]) {
                ans.push(minRow[i]);
                break;
            }
        }
    }

    return ans;
};