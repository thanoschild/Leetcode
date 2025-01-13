/**
 * @param {string} s
 * @return {number}
 */
var minimumLength = function(s) {
    const freq = new Array(26).fill(0);

    for (let c of s) {
        freq[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    let ans = 0;
    for (let i = 0; i < 26; i++) {
        if (freq[i] === 0) continue;
        if (freq[i] % 2 === 0) {
            ans += 2;
        } else {
            ans += 1;
        }
    }

    return ans;
};