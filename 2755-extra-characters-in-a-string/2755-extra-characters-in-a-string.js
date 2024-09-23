/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {number}
 */
function dfs(s, dp, wordSet, idx) {
    if (idx >= s.length) return 0;
    if (dp[idx] !== -1) return dp[idx];

    let minlen = s.length;
    let currStr = "";
    for (let i = idx; i < s.length; i++) {
        currStr += s[i];
        let count = wordSet.has(currStr) ? 0 : currStr.length;
        let newCount = dfs(s, dp, wordSet, i + 1);
        minlen = Math.min(minlen, count + newCount);
    }

    dp[idx] = minlen;
    return dp[idx];
}

var minExtraChar = function(s, dictionary) {
    let dp = Array(s.length).fill(-1);
    let wordSet = new Set(dictionary);  
    return dfs(s, dp, wordSet, 0);
};