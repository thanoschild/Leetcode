/**
 * @param {number[]} original
 * @param {number} m
 * @param {number} n
 * @return {number[][]}
 */
var construct2DArray = function(original, m, n) {
    const len = original.length;
    if (n * m !== len) return [];

    const ans = [];
    let idx = 0;
    for (let i = 0; i < m; i++) {
        const row = [];
        for (let j = 0; j < n; j++) {
            row.push(original[idx]);
            idx++;
        }
        ans.push(row);
    }

    return ans;
};