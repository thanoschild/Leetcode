/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let maxSum = Number.MIN_SAFE_INTEGER, currSum = 0;
    for(let num of nums) {
        currSum = Math.max(currSum, 0) + num;
        maxSum = Math.max(maxSum, currSum);
    }

    return maxSum;
};