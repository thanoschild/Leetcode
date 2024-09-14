/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    let mx = -1, count = 0, ans = 0;
    for(let it of nums) mx = Math.max(mx, it);

    for(let it of nums) {
        if(mx == it) count++;
        else count = 0;
        ans = Math.max(ans, count);
    }

    return ans;
};