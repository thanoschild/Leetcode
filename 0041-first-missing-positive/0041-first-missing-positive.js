/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    let n = nums.length;
    let seen = new Array(n + 1).fill(0);

    for(let val of nums) {
        if(val >= 0 && val <= n) {
            seen[val] = 1
        }
    }

    for(let i = 1; i<=n; i++) {
        if(seen[i] == 0) return i;
    }

    return n + 1;
};