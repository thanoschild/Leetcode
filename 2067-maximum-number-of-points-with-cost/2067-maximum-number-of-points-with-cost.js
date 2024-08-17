/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(arr) {
    const n = arr.length;
    const m = arr[0].length;
    const dp = Array.from({ length: n }, () => Array(m).fill(0));

    for (let j = 0; j < m; j++) {
      dp[0][j] = arr[0][j];
    }

    for (let i = 1; i < n; i++) {
      const left_dp = Array(m).fill(0);
      const right_dp = Array(m).fill(0);

      left_dp[0] = dp[i - 1][0]; 
      for (let j = 1; j < m; j++) {
        left_dp[j] = Math.max(left_dp[j - 1], dp[i - 1][j] + j);
      }

      right_dp[m - 1] = dp[i - 1][m - 1] - (m - 1); 
      for (let j = m - 2; j >= 0; j--) {
        right_dp[j] = Math.max(right_dp[j + 1], dp[i - 1][j] - j);
      }

      for (let j = 0; j < m; j++) {
        dp[i][j] = Math.max(left_dp[j] - j, right_dp[j] + j) + arr[i][j];
      }
    }

    return Math.max(...dp[n - 1]);
};