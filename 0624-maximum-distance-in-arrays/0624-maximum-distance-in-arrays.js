/**
 * @param {number[][]} arrays
 * @return {number}
 */
var maxDistance = function(arrays) {
    let mx = arrays[0][arrays[0].length - 1];  
    let mn = arrays[0][0];  
    let diff = 0;

    for (let i = 1; i < arrays.length; i++) {
        let currMax = arrays[i][arrays[i].length - 1];
        let currMin = arrays[i][0];

        diff = Math.max(diff, Math.abs(mx - currMin));
        diff = Math.max(diff, Math.abs(currMax - mn));

        mx = Math.max(mx, currMax);
        mn = Math.min(mn, currMin);
    }

    return diff;
};