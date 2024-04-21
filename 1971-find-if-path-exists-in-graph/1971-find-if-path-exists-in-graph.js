/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} source
 * @param {number} destination
 * @return {boolean}
 */
var validPath = function(n, edges, source, destination) {
    const seen = new Array(n).fill(false);
    let adj = Array.from({length : n}, () => []);

    for(let it of edges) {
        adj[it[0]].push(it[1]);
        adj[it[1]].push(it[0]);
    }

    dfs = (idx) => {
        seen[idx] = true;
        if(seen[destination]) return;

        for(let edge of adj[idx]) {
            if(!seen[edge]) dfs(edge)
        }
    }

    dfs(source);
    return seen[destination];
};