/**
 * @param {string} num
 * @param {number} k
 * @return {string}
 */
var removeKdigits = function(num, k) {
    const n = num.length;
    const chars = [...num];
    let ans = [];
    ans.push(chars[0]);

    for(let i = 1; i<n; i++) {
        while(ans.length > 0 && chars[i] < ans[ans.length - 1] && k > 0) {
            ans.pop();
            k--;
        }
        if(chars[i] != '0' || ans.length > 0) ans.push(chars[i]);
    }

    while(ans.length > 0 && k > 0) {
        ans.pop();
        k--;
    }

    return ans.length == 0 ? "0" : ans.join('');
};