/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxSubarrayLength = function(nums, k) {
    let n = nums.length, ans = 0;
    let mp = new Map();

    for(let i = 0, j = 0; j<n; j++) {
        mp.set(nums[j], (mp.get(nums[j]) || 0) + 1);
        if(mp.get(nums[j]) > k) {
            while(nums[i] !== nums[j]) {
                mp.set(nums[i], mp.get(nums[i]) - 1);
                i++;
            }
            mp.set(nums[i], mp.get(nums[i]) - 1);
            i++;
        }
        ans = Math.max(ans, j - i + 1);
    }

    return ans;
};