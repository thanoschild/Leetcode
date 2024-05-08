/**
 * @param {number[]} score
 * @return {string[]}
 */
var findRelativeRanks = function(score) {
    const n = score.length;
    const pair = new Array(n);
    
    for (let i = 0; i < n; i++) {
        pair[i] = [score[i], i];
    }

    pair.sort((a, b) => b[0] - a[0]);
    const ans = new Array(n);

    for (let i = 0; i < n; i++) {
        if (i === 0) {
            ans[pair[i][1]] = "Gold Medal";
        } else if (i === 1) {
            ans[pair[i][1]] = "Silver Medal";
        } else if (i === 2) {
            ans[pair[i][1]] = "Bronze Medal";
        } else {
            ans[pair[i][1]] = String(i + 1);
        }
    }

    return ans;
};