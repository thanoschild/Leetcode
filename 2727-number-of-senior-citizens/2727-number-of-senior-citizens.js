/**
 * @param {string[]} details
 * @return {number}
 */
var countSeniors = function(details) {
    let ans = 0;
    for (let s of details) {
        let age = (parseInt(s.charAt(11)) * 10) + parseInt(s.charAt(12));
        if (age > 60) ans++;
    }
    return ans;
};