/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[][]}
 */
function dfs(x, curr, ans, child) {
    for (let it of child[curr]) {
        if (ans[it].length === 0 || ans[it][ans[it].length - 1] !== x) {
            ans[it].push(x);
            dfs(x, it, ans, child);
        }
    }
}

var getAncestors = function(n, edges) {
    let ans = Array.from({ length: n }, () => []);
    let child = Array.from({ length: n }, () => []);

    for (let e of edges) {
        child[e[0]].push(e[1]);
    }

    for (let i = 0; i < n; i++) {
        dfs(i, i, ans, child);
    }

    return ans;
};