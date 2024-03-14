/**
 * @param {number[]} nums
 * @param {number} goal
 * @return {number}
 */
var numSubarraysWithSum = function(nums, goal) {
    const map = new Map();
    let sum = 0;
    let ans = 0;
    map.set(0, 1);

    for(let it of nums) {
        sum += it;
        if(map.has(sum - goal)) ans += map.get(sum - goal);
        if(!map.has(sum)) map.set(sum, 1);
        else map.set(sum, map.get(sum) + 1);
    }

    return ans;
};