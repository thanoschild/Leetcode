/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    let n = heights.length, ans = 0;
    st = [];

    for(let i = 0; i<=n; i++) {
        while(st.length > 0 && (i == n || heights[st[st.length - 1]] > heights[i])) {
            let h = heights[st.pop()];
            let l = st.length == 0 ? i : i - st[st.length - 1] - 1;
            ans = Math.max(ans, l * h);
        }
        st.push(i);
    }

    return ans;
};