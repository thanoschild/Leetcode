/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalRectangle = function(mat) {
    const n = mat.length;
    const m = mat[0].length;
    const dp = new Array(n).fill(0).map(() => new Array(m).fill(0));

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (i === 0) {
                dp[i][j] = mat[i][j] - '0';
            } else {
                if (mat[i][j] === '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }
    }

    let ans = 0;
    for (let i = 0; i < n; i++) {
        const st = [];
        for (let j = 0; j <= m; j++) {
            const curr = j === m ? 0 : dp[i][j];
            while (st.length && dp[i][st[st.length - 1]] > curr) {
                const h = dp[i][st.pop()];
                const l = st.length === 0 ? j : j - st[st.length - 1] - 1;
                ans = Math.max(ans, l * h);
            }
            st.push(j);
        }
    }

    return ans;
};