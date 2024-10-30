/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumMountainRemovals = function(nums) {
    const n = nums.length;
    if(n < 2) return -1;
    const left = Array(n).fill(1);
    const right = Array(n).fill(1);

    for(let i = 1; i<n; i++) {
        for(let j = 0; j<i; j++) {
            if(nums[i] > nums[j]) left[i] = Math.max(left[i], 1 + left[j]);
        }
    }

    for(let i = n - 2; i>=0; i--) {
        for(let j = n-1; j>i; j--) {
            if(nums[i] > nums[j]) right[i] = Math.max(right[i], 1 + right[j]);
        }
    }

    let maxLen = 0;
    for(let i = 1; i<n-1; i++) {
        if (left[i] > 1 && right[i] > 1) { 
            maxLen = Math.max(maxLen, left[i] + right[i] - 1);
        }
    }

    return n - maxLen;
};