/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */

function solve(idx, curr, arr, sum, ans) {
    if (sum === 0) {
        ans.push([...curr]); 
        return;
    }

    for (let i = idx; i < arr.length; i++) {
        if (i > idx && arr[i] === arr[i - 1]) continue;  
        if (sum < arr[i]) break;  

        curr.push(arr[i]);
        solve(i + 1, curr, arr, sum - arr[i], ans);  
        curr.pop();  
    }
}

var combinationSum2 = function(arr, target) {
    const ans = [];
    arr.sort((a, b) => a - b);  
    solve(0, [], arr, target, ans);
    return ans;
};