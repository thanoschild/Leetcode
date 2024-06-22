/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
function atMostK(nums, k) {
   let ans = 0, count = 0;
    for(let i = 0, j = 0; i<nums.length; i++) {
        count += nums[i] % 2;
        while(count > k) {
            count -= nums[j++] % 2; 
        }
        ans += (i - j);
    }

    return ans;
};

var numberOfSubarrays = function(nums, k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
};