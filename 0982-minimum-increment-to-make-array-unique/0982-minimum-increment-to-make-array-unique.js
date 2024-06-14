/**
 * @param {number[]} nums
 * @return {number}
 */
var minIncrementForUnique = function(nums) {
    nums.sort((a, b) => a - b);
    let ans = 0, need = 0;
    for(let n of nums) {
        ans += Math.max(need - n, 0);
        need = Math.max(n, need) + 1;
    }

    return ans;
};