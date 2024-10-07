/**
 * @param {string} s
 * @return {number}
 */
var minLength = function(s) {
    let ans = "";
    
    for (let c of s) {
        if (ans.length > 0 && ((c === 'B' && ans[ans.length - 1] === 'A') || (c === 'D' && ans[ans.length - 1] === 'C'))) {
            ans = ans.slice(0, -1);  
        } else {
            ans += c;
        }
    }

    return ans.length;
};