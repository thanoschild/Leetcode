/**
 * @param {string} s
 * @param {string} t
 * @param {number} maxCost
 * @return {number}
 */
var equalSubstring = function(s, t, maxCost) {
     let n = s.length, i = 0, j = 0;

    while (i < n) {
        let a = s.charCodeAt(i) - 'a'.charCodeAt(0);
        let b = t.charCodeAt(i) - 'a'.charCodeAt(0);
        maxCost -= Math.abs(a - b);
        if (maxCost < 0) {
            let a1 = s.charCodeAt(j) - 'a'.charCodeAt(0);
            let b1 = t.charCodeAt(j) - 'a'.charCodeAt(0);
            maxCost += Math.abs(a1 - b1);
            j++;
        }
        i++;
    }

    return i - j;
};