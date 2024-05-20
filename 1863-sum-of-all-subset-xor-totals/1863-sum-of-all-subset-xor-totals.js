/**
 * @param {number[]} nums
 * @return {number}
 */
var subsetXORSum = function(nums) {
    let n = nums.length;
    let ans = 0;

    for(let i = 1; i<(1 << n); i++) {
        let total = 0;
        for(let j = 0; j<n; j++) {
            if((i & (1 << j)) >= 1) {
                total ^= nums[j];
            }
        }
        ans += total;
    }

    return ans;
};