/**
 * @param {number[]} arr
 * @return {number}
 */
var countTriplets = function(arr) {
    const n = arr.length + 1;
    let ans = 0;
    let prefix = Array(n).fill(0);

    for(let i = 1; i<n; i++) {
       prefix[i] = prefix[i-1] ^ arr[i-1];
    }

    for(let i = 0; i<n; i++) {
        for(let j = i+1; j<n; j++) {
            if(prefix[i] == prefix[j]) {
                ans += (j - i -1);
            }
        }
    }

    return ans;
};