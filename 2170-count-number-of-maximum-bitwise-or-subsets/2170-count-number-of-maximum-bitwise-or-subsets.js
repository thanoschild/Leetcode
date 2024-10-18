/**
 * @param {number[]} nums
 * @return {number}
 */

const ans = new Array(1).fill(0);

function maxSubset(nums, idx, currOr, maxOr) {
    if (idx === nums.length) {
        if (currOr === maxOr) {
            ans[0] += 1;
        }
        return;
    }

    maxSubset(nums, idx + 1, currOr | nums[idx], maxOr);
    maxSubset(nums, idx + 1, currOr, maxOr);
}

var countMaxOrSubsets = function(nums) {
    let maxOr = 0;
    ans[0] = 0;

    for (let n of nums) {
        maxOr |= n;
    }

    maxSubset(nums, 0, 0, maxOr);

    return ans[0];
};