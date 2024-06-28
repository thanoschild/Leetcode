/**
 * @param {number} n
 * @param {number[][]} roads
 * @return {number}
 */
var maximumImportance = function(n, roads) {
    let indeg = new Array(n).fill(0);
    for(let x of roads) {
        indeg[x[0]]++;
        indeg[x[1]]++;
    }

    indeg.sort((a, b) => a - b);
    let ans = 0, val = 1;
    for(let x of indeg) {
        ans += (x * val);
        val++;
    }

    return ans;
};