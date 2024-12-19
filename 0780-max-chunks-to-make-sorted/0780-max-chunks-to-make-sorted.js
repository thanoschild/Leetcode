/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function(arr) {
    const n = arr.length;
    let ans = 0, maxVal = 0;

    for(let i = 0; i<n; i++) {
        maxVal = Math.max(maxVal, arr[i]);
        if(maxVal == i) ans++;
    }

    return ans;
};