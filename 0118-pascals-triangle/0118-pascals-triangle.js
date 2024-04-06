/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    const ans = [];
    for(let i = 0; i<numRows; i++) {
        curr = new Array(i+1).fill(1);
        for(let j = 1; j<i; j++) {
            curr[j] = ans[i-1][j] + ans[i-1][j-1];
        }
        ans.push(curr);
    } 

    return ans;
};