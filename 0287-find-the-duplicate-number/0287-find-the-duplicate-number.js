/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    for(let i = 0; i<nums.length; i++) {
        let idx = Math.abs(nums[i]) - 1;
        nums[idx] *= -1;
        if(nums[idx] > 0) return Math.abs(nums[i]);
    }

    return -1;
};