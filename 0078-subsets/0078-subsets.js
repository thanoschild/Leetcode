/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    const n = nums.length;
    let ans = [];
    for(let i = 0; i<(1 << n); i++) {
        curr = []
        for(let j = 0; j<n; j++) {
            if((i & (1 << j)) > 0) {
                curr.push(nums[j]);
            }
        }
        ans.push(curr);
    }

    return ans;
};