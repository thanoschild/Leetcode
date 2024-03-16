/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxLength = function(nums) {
    let mp = new Map();
    mp.set(0, -1);
    let sum = 0, maxLen = 0;
    let n = nums.length;

    for(let i = 0; i<n; i++) {
        sum += nums[i] == 0 ? -1 : 1;
        if(mp.has(sum)) {
            maxLen = Math.max(maxLen, i - mp.get(sum));
        }
        else mp.set(sum, i);
    }

    return maxLen;
};