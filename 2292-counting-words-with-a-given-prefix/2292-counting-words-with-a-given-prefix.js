/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
var prefixCount = function(words, pref) {
    const n = pref.length;
    let ans = 0;
    for(const word of words) {
        if(word.substr(0, n) == pref) ans++;
    }

    return ans;
};