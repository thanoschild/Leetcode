/**
 * @param {number[]} arr
 * @param {number} k
 * @return {boolean}
 */
var canArrange = function(arr, k) {
    const freq = new Array(k).fill(0);
    for(let it of arr) {
        let rem = (it % k + k) % k;
        freq[rem]++;
    }

    for(let i = 1; i<=k/2; i++) {
        if(freq[i] != freq[k - i]) return false;
    }

    return freq[0] % 2 === 0;
};