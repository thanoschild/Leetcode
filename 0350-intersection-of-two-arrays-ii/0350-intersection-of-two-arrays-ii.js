/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    const ans = [];
    const mp = new Map();

    for(const num of nums1) {
        mp.set(num, (mp.get(num) || 0) + 1);
    }

    for(const num of nums2) {
        if(mp.has(num) && mp.get(num) > 0) {
            ans.push(num);
            mp.set(num, mp.get(num) - 1);
        }
    }

    return ans;
};