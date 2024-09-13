/**
 * @param {number[]} arr
 * @param {number[][]} queries
 * @return {number[]}
 */
var xorQueries = function(arr, queries) {
    const n = arr.length, m = queries.length;
    const xors = new Array(n);
    const ans = new Array(m);

    let _xor = 0;
    for(let i = 0; i<n; i++) {
        _xor ^= arr[i];
        xors[i] = _xor;
    }

    for(let i = 0; i<m; i++) {
        let start = queries[i][0];
        let end = queries[i][1];
        if(start == 0) ans[i] = xors[end];
        else ans[i] = xors[end] ^ xors[start-1];
    }

    return ans;
};