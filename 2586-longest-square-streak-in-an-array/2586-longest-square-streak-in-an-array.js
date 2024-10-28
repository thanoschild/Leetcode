/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSquareStreak = function(nums) {
    const mp = new Map();
    let ans = 0;
    nums.sort((a, b) => a - b);

    for(const it of nums) {
        const root = Math.floor(Math.sqrt(it));
        if(root * root == it) {
            mp.set(it, (mp.get(root) || 0) + 1);
        } else {
            mp.set(it, 1);
        }

        ans = Math.max(ans, mp.get(it));
    }

    return ans < 2 ? -1 : ans;
};