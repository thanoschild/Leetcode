/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function(heights) {
    let expected = [...heights].sort((a, b) => a - b);
    let ans = 0;
    let n = heights.length;
    for (let i = 0; i < n; i++) {
        if (heights[i] != expected[i]) ans++;
    }
    return ans;
};