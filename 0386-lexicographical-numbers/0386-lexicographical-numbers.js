/**
 * @param {number} n
 * @return {number[]}
 */
function dfs(curr, n, ans) {
    if(curr > n) return;
    ans.push(curr);
    for(let i = 0; i<10; i++) {
        if(10 * curr + i > n) return;
        dfs(10 * curr + i, n, ans)
    }
}

var lexicalOrder = function(n) {
    const ans = [];
    for(let i = 1; i<10; i++) {
        dfs(i, n, ans);
    }

    return ans;
};