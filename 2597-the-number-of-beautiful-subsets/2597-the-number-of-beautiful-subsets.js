/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
function dfs(nums, idx, mp, ans, k) {
    if (idx === nums.length) {
        ans.count++;
        return;
    }

    if ((mp[nums[idx] - k] || 0) === 0 && (mp[nums[idx] + k] || 0) === 0) {
        mp[nums[idx]] = (mp[nums[idx]] || 0) + 1;
        dfs(nums, idx + 1, mp, ans, k);
        mp[nums[idx]]--;
    }
    dfs(nums, idx + 1, mp, ans, k);
}

var beautifulSubsets = function(nums, k) {
    let ans = { count: 0 };
    let mp = {};
    dfs(nums, 0, mp, ans, k);
    return ans.count - 1;
};