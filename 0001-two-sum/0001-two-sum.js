/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const mp = new Map();
    
    for(let i = 0; i<nums.length; i++) {
        if(mp.has(target - nums[i])) {
            return [mp.get(target - nums[i]), i];
        }
        else {
            mp.set(nums[i], i);
        }
    }

    return [];
};