/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minOperations = function(nums, k) {
    let _xor = 0;
    for (let num of nums) _xor ^= num;

    let count = 0;
    while (k > 0 || _xor > 0) {
        if ((k % 2) !== (_xor % 2)) count++;
        k = Math.floor(k / 2);
        _xor = Math.floor(_xor / 2);
    }

    return count;
};