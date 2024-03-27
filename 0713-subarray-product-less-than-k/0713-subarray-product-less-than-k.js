/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function(nums, k) {
    let n = nums.length;
    let count = 0, pro = 1;

    for(let i = 0, j = 0; j<n; j++) {
        pro *= nums[j];
        while(i <= j && pro >= k) {
            pro /= nums[i];
            i++;
        }
        count += (j - i + 1);
    }

    return count;
};