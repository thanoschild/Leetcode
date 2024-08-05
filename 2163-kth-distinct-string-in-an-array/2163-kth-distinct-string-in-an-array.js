/**
 * @param {string[]} arr
 * @param {number} k
 * @return {string}
 */
var kthDistinct = function(arr, k) {
    const mp = new Map();
    for(const s of arr) {
        mp.set(s, (mp.get(s) || 0) + 1);
    }

    for(const s of arr) {
        if(mp.get(s) == 1 && --k == 0) return s;
    }

    return "";
};