/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

function findkMostSubarrays(nums, n, k) {
   let count = 0;
   mp = new Map();

   for(let i = 0, j = 0; j<n; j++) {
       mp.set(nums[j], (mp.get(nums[j]) || 0) + 1);
       while(mp.size > k) {
           mp.set(nums[i], mp.get(nums[i]) - 1);
           if(mp.get(nums[i]) === 0) mp.delete(nums[i]);
           i++;
       }
       count += (j - i + 1);
   }

   return count;
};

var subarraysWithKDistinct = function(nums, k) {
    let n = nums.length;
    let ans1 = findkMostSubarrays(nums, n, k);
    let ans2 = findkMostSubarrays(nums, n, k - 1);
    return ans1 - ans2;
};