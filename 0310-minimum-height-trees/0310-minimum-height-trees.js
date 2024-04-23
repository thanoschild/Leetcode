/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    if (n === 0) return [];
    else if (n === 1) return [0];

    let adj = Array.from({ length: n }, () => []);
    let indegree = Array(n).fill(0);

    for (let [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
        indegree[u]++;
        indegree[v]++;
    }

    let ans = [];
    let pq = [];
    for (let i = 0; i < n; i++) {
        if (indegree[i] === 1) pq.push(i);
    }

    while (pq.length > 0) {
        ans = [];
        let length = pq.length;
        for (let i = 0; i < length; i++) {
            let curr = pq.shift();
            ans.push(curr);

            for (let neighbor of adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] === 1) {
                    pq.push(neighbor);
                }
            }
        }
    }

    return ans;
};