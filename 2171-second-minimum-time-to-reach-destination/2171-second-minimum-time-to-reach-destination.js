/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} time
 * @param {number} change
 * @return {number}
 */
var secondMinimum = function(n, edges, time, change) {
    const adj = Array.from({ length: n + 1 }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }

    const pq = [];
    pq.push([1, 0]);
    const visitedTime = Array(n + 1).fill(0);
    const visited = Array(n + 1).fill(0);
    let firstVisited = Number.MAX_VALUE;

    while (pq.length > 0) {
        const [node, t] = pq.shift();
        for (const next of adj[node]) {
            let t2 = t;
            const isReg = Math.floor(t2 / change) % 2;
            if (isReg === 1) {
                t2 += change - (t2 % change);
            }
            t2 += time;

            if (next === n && firstVisited === Number.MAX_VALUE) {
                firstVisited = t2;
            }
            if (next === n && firstVisited < t2) {
                return t2;
            }
            if (visitedTime[next] !== t2 && visited[next] <= 1) {
                visited[next]++;
                visitedTime[next] = t2;
                pq.push([next, t2]);
            }
        }
    }

    return -1;
};