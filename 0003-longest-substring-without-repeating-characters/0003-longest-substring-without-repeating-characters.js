/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    const n = s.length;
    if (n === 1) return 1;

    const freq = new Array(256).fill(-1);
    let start = -1, count = 0;

    for (let i = 0; i < n; i++) {
        if (freq[s.charCodeAt(i)] > start) {
            start = freq[s.charCodeAt(i)];
        }

        freq[s.charCodeAt(i)] = i;
        count = Math.max(count, i - start);
    }

    return count;
};