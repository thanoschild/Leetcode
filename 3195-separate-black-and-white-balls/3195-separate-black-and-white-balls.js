/**
 * @param {string} s
 * @return {number}
 */
var minimumSteps = function(s) {
    let ans = 0, count = 0;
    for(const c of s) {
        if(c == '1') count++;
        else ans += count;
    }

    return ans;
};