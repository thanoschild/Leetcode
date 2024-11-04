/**
 * @param {string} word
 * @return {string}
 */
var compressedString = function(word) {
    let ans = '';
    let count = 1;
    const n = word.length;
    let prev = word[0];

    for(let i = 1; i<n; i++) {
        let c = word[i];
        if(prev === c && count < 9) count++;
        else {
            ans += count + prev;
            prev = c;
            count = 1;
        }
    }

    ans += count + prev;
    return ans;
};