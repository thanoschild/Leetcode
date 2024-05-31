/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function(nums) {
    const n = nums.length;
    let _xor = 0;
    for(let i = 0; i<n; i++) _xor ^= nums[i];

    let rightBit = _xor & (-_xor);
    let x = 0, y = 0;

    for(let i = 0; i<n; i++) {
        if((rightBit & nums[i]) == 0) x ^= nums[i];
        else y ^= nums[i];
    }

    return [x, y];
};