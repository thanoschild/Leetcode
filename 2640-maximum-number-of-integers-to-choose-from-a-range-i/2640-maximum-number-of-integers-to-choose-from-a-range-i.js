/**
 * @param {number[]} banned
 * @param {number} n
 * @param {number} maxSum
 * @return {number}
 */
var maxCount = function(banned, n, maxSum) {
    const st = new Set();
    for(const num of banned) st.add(num);

    let sum = 0, count = 0;
    for(let i = 1; i<=n; i++) {
        if(!st.has(i)) {
            sum += i;
            if(sum > maxSum) break;
            count++;
        }
    }

    return count;
};