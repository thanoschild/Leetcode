/**
 * @param {number[]} nums
 * @return {number}
 */
var minDifference = function(nums) {
    const n = nums.length;
    if(n < 5) return 0;
    nums.sort((a, b) => a - b);
    const a = nums[n-1] - nums[3];
    const b = nums[n-2] - nums[2];
    const c = nums[n-3] - nums[1];
    const d = nums[n-4] - nums[0];
    const ans = Math.min(a, Math.min(b, Math.min(c, d)));
    return ans;
};