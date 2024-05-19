/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number[][]} edges
 * @return {number}
 */
var maximumValueSum = function(nums, k, edges) {
    let n = nums.length;
    let delta = new Array(n);
    for (let i = 0; i < n; i++) {
        delta[i] = (nums[i] ^ k) - nums[i];
    }

    let ans = 0;
    for (let num of nums) ans += num;
    delta.sort((a, b) => b - a);

    for (let i = 0; i < n; i += 2) {
        if (i == n - 1) break;
        let curr_delta = delta[i] + delta[i + 1];
        if (curr_delta <= 0) break;
        ans += curr_delta;
    }

    return ans;
};