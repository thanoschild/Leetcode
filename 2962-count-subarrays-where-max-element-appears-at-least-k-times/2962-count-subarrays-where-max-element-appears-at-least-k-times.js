/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) {
    let n = nums.length, ans = 0, count = 0;
    let maxEle = Math.max(...nums);

    for(let i = 0, j = 0; j<n; j++) {
        count += nums[j] === maxEle ? 1 : 0;
        while (count >= k) {
            count -= nums[i] === maxEle ? 1 : 0;
            i++;
        }
        ans += i;
    }

    return ans;
};