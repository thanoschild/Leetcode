/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function(logs) {
    let ans = 0;
    for(let s of logs) {
        if(s === "../") ans = Math.max(0, --ans);
        else if(s === "./") continue;
        else ans++;
    }

    return ans;
};