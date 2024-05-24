/**
 * @param {string[]} words
 * @param {character[]} letters
 * @param {number[]} score
 * @return {number}
 */

function solve(words, count, score, idx) {
    let ans = 0;
    for (let i = idx; i < words.length; i++) {
        let curr = 0;
        let flag = true;
        for (let c of words[i]) {
            count[c.charCodeAt(0) - 'a'.charCodeAt(0)]--;
            curr += score[c.charCodeAt(0) - 'a'.charCodeAt(0)];
            if (count[c.charCodeAt(0) - 'a'.charCodeAt(0)] < 0) flag = false;
        }
        if (flag) {
            curr += solve(words, count, score, i + 1);
            ans = Math.max(ans, curr);
        }
        for (let c of words[i]) {
            count[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        curr = 0;
    }
    return ans;
}

var maxScoreWords = function(words, letters, score) {
    let n = words.length, m = letters.length, p = score.length;
    if (n === 0 || m === 0 || p === 0) return 0;
    let count = new Array(p).fill(0);
    for (let c of letters) {
        count[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    return solve(words, count, score, 0);
};