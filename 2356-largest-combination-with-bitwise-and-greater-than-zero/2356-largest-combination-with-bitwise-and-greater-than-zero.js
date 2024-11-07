/**
 * @param {number[]} candidates
 * @return {number}
 */
var largestCombination = function(candidates) {
    let ans = 0, curr = 0;
    for(let i = 1; i<=10000000; i <<= 1) {
        curr = 0;
        for(const n of candidates) {
            if((n & i) > 0) curr++;
        }
        ans = Math.max(ans, curr);
    }

    return ans;
};