/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var findThePrefixCommonArray = function(A, B) {
    const n = A.length;
    let count = 0;
    freq = new Array(n + 1).fill(0);
    ans = new Array(n);

    for(let i = 0; i<n; i++) {
        if(++freq[A[i]] === 2) count++;
        if(++freq[B[i]] === 2) count++;
        ans[i] = count;
    }

    return ans;
};