/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
class UnionFind {
    constructor(n) {
        this.parent = Array.from({ length: n }, (_, i) => i);
        this.sz = Array(n).fill(1);
    }

    findSet(x) {
        if (this.parent[x] !== x) {
            this.parent[x] = this.findSet(this.parent[x]);
        }
        return this.parent[x];
    }

    makeUnion(x, y) {
        let a = this.findSet(x);
        let b = this.findSet(y);
        if (a === b) return 0;
        if (this.sz[a] < this.sz[b]) {
            [a, b] = [b, a];
        }
        this.sz[a] += this.sz[b];
        this.parent[b] = a;
        return 1;
    }

    count(x) {
        const root = this.findSet(x);
        return this.sz[root];
    }
}

var maxNumEdgesToRemove = function(n, edges) {
    const alice = [];
    const bob = [];
    const both = [];

    for (let [t, x, y] of edges) {
        x -= 1;
        y -= 1;
        if (t === 3) {
            both.push([x, y]);
        } else if (t === 2) {
            bob.push([x, y]);
        } else {
            alice.push([x, y]);
        }
    }

    const a = new UnionFind(n);
    const b = new UnionFind(n);
    let requiredEdges = 0;

    for (let [x, y] of both) {
        requiredEdges += a.makeUnion(x, y);
        b.makeUnion(x, y);
    }

    for (let [x, y] of alice) {
        requiredEdges += a.makeUnion(x, y);
    }

    for (let [x, y] of bob) {
        requiredEdges += b.makeUnion(x, y);
    }

    if (a.count(0) < n || b.count(0) < n) return -1;

    return edges.length - requiredEdges;
};