/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysDivByK = function(nums, k) {
    const freq = new Array(k).fill(0);
    freq[0]++;

    let sum = 0, count = 0, rem = 0;
    for(let n of nums) {
        sum += n;
        rem = sum % k;
        if(rem < 0) rem += k;
        if(freq[rem] != 0) count += freq[rem];
        freq[rem]++;
    }

    return count;
};