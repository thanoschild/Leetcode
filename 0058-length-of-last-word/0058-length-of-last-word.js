/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let idx = s.length - 1, ans = 0;
    while(idx >= 0 && s[idx] === ' ') idx--;
    while(idx >= 0 && s[idx] !== ' ') {
        idx--;
        ans++;
    }

    return ans;
};