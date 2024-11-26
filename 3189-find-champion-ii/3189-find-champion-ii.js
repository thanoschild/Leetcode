/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var findChampion = function(n, edges) {
    const indegree = new Array(n).fill(0);
    for(const e of edges) {
        indegree[e[1]]++;
    }

    let ans = [];
    for(let i = 0; i<n; i++) {
        if(indegree[i] === 0) ans.push(i);
    }

    return ans.length == 1 ? ans[0] : -1;
};