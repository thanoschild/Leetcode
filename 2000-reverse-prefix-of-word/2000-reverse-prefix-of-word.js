/**
 * @param {string} word
 * @param {character} ch
 * @return {string}
 */
var reversePrefix = function(word, ch) {
    let ans = [], flag = true;

    for(let c of [...word]) {
        if(c == ch && flag) {
            ans.push(c);
            ans = ans.reverse();
            flag = false;
        }
        else {
            ans.push(c);
        }
    }

    return ans.join("");
};