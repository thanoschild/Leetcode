/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */

function dfs(adj, root, parent, count, ans) {
    for (let node of adj[root]) {
        if (node === parent) continue;
        dfs(adj, node, root, count, ans);
        count[root] += count[node];
        ans[root] += ans[node] + count[node];
    }
}

function dfs2(adj, root, parent, count, ans) {
    for (let node of adj[root]) {
        if (node === parent) continue;
        ans[node] = ans[root] - count[node] + count.length - count[node];
        dfs2(adj, node, root, count, ans);
    }
}

var sumOfDistancesInTree = function(n, edges) {
    const count = new Array(n).fill(1);
    const ans = new Array(n).fill(0);

    const adj = Array.from({length : n}, () => []);
    for(let edge of edges) {
        adj[edge[0]].push(edge[1]);
        adj[edge[1]].push(edge[0]);
    }
   
    dfs(adj, 0, -1, count, ans);
    dfs2(adj, 0, -1, count, ans);
    return ans;
};