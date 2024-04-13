/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */

function swap(nums, x, y) {
   let temp = nums[x];
   nums[x] = nums[y];
   nums[y] = temp;
};

var sortColors = function(nums) {
    let left = 0, mid = 0, right = nums.length-1;
    while(mid <= right) {
        if(nums[mid] == 0) {
            swap(nums, left, mid);
            left++;
            mid++;
        }
        else if(nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums, mid, right);
            right--;
        }
    }
};