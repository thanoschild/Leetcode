/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var appendCharacters = function(s, t) {
    let i = 0, j = 0;
    const n = s.length, m = t.length;

    while (i < n && j < m) {
        if (s[i] === t[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }

    return m - j;
};