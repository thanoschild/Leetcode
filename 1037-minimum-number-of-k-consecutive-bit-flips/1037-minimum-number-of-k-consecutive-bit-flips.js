/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minKBitFlips = function(nums, k) {
    const n = nums.length;
    let ans = 0, currFlips = 0;

    for(let i = 0; i<n; i++) {
        if(i - k >= 0 && nums[i-k] == 2) {
            currFlips--;
        }

        if((nums[i]+currFlips) % 2 == 0) {
            if(i+k > n) return -1;
            ans++;
            currFlips++;
            nums[i] = 2;
        }
    }

    return ans;
};