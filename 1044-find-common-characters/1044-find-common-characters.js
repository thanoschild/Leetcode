/**
 * @param {string[]} words
 * @return {string[]}
 */
var commonChars = function(words) {
    let seen = new Array(26).fill(Infinity);

    words.forEach(word => {
        let count = new Array(26).fill(0);
        for (let char of word) {
            count[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        for (let i = 0; i < 26; i++) {
            seen[i] = Math.min(seen[i], count[i]);
        }
    });

    let ans = [];
    for (let i = 0; i < 26; i++) {
        for (let j = 0; j < seen[i]; j++) {
            ans.push(String.fromCharCode('a'.charCodeAt(0) + i));
        }
    }

    return ans;
};