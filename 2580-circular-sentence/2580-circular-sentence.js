/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function(s) {
    const n = s.length;
    if(s[0] != s[n-1]) return false;

    for(let i = 1; i<n-1; i++) {
        if(s[i] == ' ' && s[i-1] != s[i+1]) return false;
    }

    return true;
};