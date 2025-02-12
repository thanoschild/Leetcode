/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumSum = function(nums) {
    const mp = new Map();
    let ans = -1;

    for(const n of nums) {
        let sum = 0, curr = n;
        while(curr > 0) {
            sum += (curr % 10);
            curr = Math.floor(curr/10);
        }

        if(mp.has(sum)) {
            ans = Math.max(ans, mp.get(sum) + n);
            if(mp.get(sum) < n) mp.set(sum, n);
        } else {
            mp.set(sum, n);
        }
    }

    return ans;
};