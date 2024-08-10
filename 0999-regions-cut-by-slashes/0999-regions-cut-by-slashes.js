/**
 * @param {string[]} grid
 * @return {number}
 */


let parent = [];
let sz = [];

function findSet(x) {
    if (parent[x] === x) return x;
    return parent[x] = findSet(parent[x]);  // Path compression
}

function makeUnion(x, y) {
    let a = findSet(x);
    let b = findSet(y);
    if (a === b) return true;

    if (sz[b] > sz[a]) {
        [a, b] = [b, a];  // Swap to ensure the larger set is the parent
    }

    parent[b] = a;
    sz[a] += sz[b];
    return false;
}

var regionsBySlashes = function(grid) {
    const n = grid.length + 1;
    parent = Array.from({ length: n * n }, (_, i) => i);
    sz = Array(n * n).fill(1);

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 || j === 0 || i === n - 1 || j === n - 1) {
                const x = i * n + j;
                makeUnion(0, x);
            }
        }
    }

    let ans = 1;
    for (let i = 0; i < grid.length; i++) {
        const s = grid[i];
        for (let j = 0; j < s.length; j++) {
            const c = s[j];
            if (c === '/') {
                const x = (i + 1) * n + j;
                const y = i * n + (j + 1);
                if (makeUnion(x, y)) ans++;
            } else if (c === '\\') {
                const x = i * n + j;
                const y = (i + 1) * n + (j + 1);
                if (makeUnion(x, y)) ans++;
            }
        }
    }

    return ans;
};