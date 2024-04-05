/**
 * @param {string} s
 * @return {string}
 */
var makeGood = function(s) {
    let ans = '';
        for (let i = 0; i < s.length; i++) {
            if (ans !== '' && Math.abs(ans.charCodeAt(ans.length - 1) - s.charCodeAt(i)) === 32) {
                ans = ans.slice(0, -1);
            } else {
                ans += s[i];
            }
        }
        
    return ans;
};