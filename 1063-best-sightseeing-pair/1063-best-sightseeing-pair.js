/**
 * @param {number[]} values
 * @return {number}
 */
var maxScoreSightseeingPair = function(values) {
    let ans = -Infinity, curr = values[0]
    for(let i = 1; i<values.length; i++) {
        ans = Math.max(ans, curr + values[i] - i);
        curr = Math.max(curr, values[i] + i);
    }

    return ans;
};