/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */

function check(freq1, freq2) {
    for(let i = 0; i<26; i++) {
        if(freq1[i] !== freq2[i]) return false;
    }
    return true;
}

var checkInclusion = function(s1, s2) {
    const n = s1.length, m = s2.length;
    if(n > m) return false;
    
    const freq1 = new Array(26).fill(0);
    const freq2 = new Array(26).fill(0);
    for(let i = 0; i<n; i++) {
        freq1[s1[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    for(let i = 0; i<n; i++) {
        freq2[s2[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    if(check(freq1, freq2)) return true;
    for(let i = n; i<m; i++) {
        freq2[s2[i - n].charCodeAt(0) - 'a'.charCodeAt(0)]--;
        freq2[s2[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
        if(check(freq1, freq2)) return true; 
    }

    return false;
};