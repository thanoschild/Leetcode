/**
 * @param {number[]} nums
 * @return {number}
 */
var minSwaps = function(nums) {
    let n = nums.length, ones = 0, zeros = 0, minSwaps = 0;

    for (let i = 0; i < n; i++) {
        if (nums[i] === 1) {
            ones++;
        }
    }

    for (let i = 0; i < ones; i++) {
        if (nums[i] === 0) {
            zeros++;
        }
    }

    minSwaps = zeros;
    for (let i = 1; i < n; i++) {
        let start = i;
        let end = (i + ones - 1) % n;
        if (nums[start - 1] === 0) {
            zeros--;
        }
        if (nums[end] === 0) {
            zeros++;
        }
        minSwaps = Math.min(minSwaps, zeros);
    }

    return minSwaps;
};