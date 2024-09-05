/**
 * @param {number[]} rolls
 * @param {number} mean
 * @param {number} n
 * @return {number[]}
 */
var missingRolls = function(rolls, mean, n) {
    const sumRolls = rolls.reduce((acc, roll) => acc + roll, 0);
    const m = rolls.length;
    const missingSum = mean * (n + m) - sumRolls;

    if (missingSum < n || missingSum > n * 6) return [];
    
    const val = Math.floor(missingSum / n);
    let rem = missingSum % n;
    const ans = Array(n).fill(val);
    
    for (let i = 0; i < rem; i++) {
        ans[i]++;
    }
    
    return ans;
};