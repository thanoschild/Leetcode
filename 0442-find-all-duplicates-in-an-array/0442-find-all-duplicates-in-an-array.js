/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    let ans = []
    for(let i = 0; i<nums.length; i++) {
        let idx = Math.abs(nums[i]) - 1;
        nums[idx] *= -1;
        if(nums[idx] > 0) ans.push(Math.abs(nums[i]));
    }

    return ans;
};