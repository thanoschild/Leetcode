/**
 * @param {number[][]} matrix
 * @return {number}
 */
var countSquares = function(matrix) {
    let n = matrix.length, m = matrix[0].length, ans = 0;
    for(let i = 0; i<n; i++) {
        for(let j = 0; j<m; j++) {
            if(i != 0 && j != 0 && matrix[i][j] != 0) {
                matrix[i][j] = Math.min(Math.min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]) + 1;
            }
            ans += matrix[i][j];
        }
    }

    return ans;
};