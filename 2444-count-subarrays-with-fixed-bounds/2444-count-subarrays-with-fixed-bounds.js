/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function(nums, minK, maxK) {
    let n = nums.length, minIdx = -1, maxIdx = -1, badIdx = 0, ans = 0;

    for(let i = 0; i<n; i++) {
        if(nums[i] < minK || nums[i] > maxK) badIdx = i + 1;
        if(nums[i] == minK) minIdx = i;
        if(nums[i] == maxK) maxIdx = i;
        ans += Math.max(0, Math.min(minIdx, maxIdx) - badIdx + 1);
    }

    return ans;
};