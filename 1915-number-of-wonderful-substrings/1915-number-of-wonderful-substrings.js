/**
 * @param {string} word
 * @return {number}
 */
var wonderfulSubstrings = function(word) {
    let ans = 0, _xor = 0;
    mp = new Map();
    mp.set(0, 1);

    for(let c of word) {
        let bit = c.charCodeAt(0) - 'a'.charCodeAt(0);
        _xor ^= (1 << bit);
        for(let i = 0; i<10; i++) ans += mp.get(_xor ^ (1 << i)) || 0;
        ans += mp.get(_xor) || 0;
        mp.set(_xor, (mp.get(_xor) || 0) + 1);
    }

    return ans;
};