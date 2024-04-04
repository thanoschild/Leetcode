/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function(s) {
    let count = 0, ans = 0;
    for(let c of s) {
        if(c === '(') count++;
        else if(c === ')') count--;
        ans = Math.max(ans, count);
    }

    return ans;
};