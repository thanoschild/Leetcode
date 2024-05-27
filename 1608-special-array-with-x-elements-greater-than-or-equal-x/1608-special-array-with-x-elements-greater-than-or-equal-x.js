/**
 * @param {number[]} nums
 * @return {number}
 */
var specialArray = function(nums) {
    const n = nums.length;
    let count = Array(n+1).fill(0);

    for(let num of nums) {
        if(num >= n) count[n]++;
        else count[num]++;
    }

    let ans = 0;
    for(let i = n; i>0; i--) {
        ans += count[i];
        if(ans == i) return ans;
    }

    return -1;
};