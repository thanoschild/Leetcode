/**
 * @param {number[]} rowSum
 * @param {number[]} colSum
 * @return {number[][]}
 */
var restoreMatrix = function(row, col) {
    const n = row.length, m = col.length;
    const ans = Array.from({ length: n}, () => Array(m).fill(0));

    for(let i = 0; i<n; i++) {
        for(let j = 0; j<m; j++) {
            ans[i][j] = Math.min(col[j], row[i]);
            row[i] -= ans[i][j];
            col[j] -= ans[i][j];
        }
    }

    return ans;
};