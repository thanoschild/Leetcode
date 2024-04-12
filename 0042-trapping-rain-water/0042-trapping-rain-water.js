/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    const n = height.length;
    const st = [];
    let ans = 0;

    for(let i = 0; i<n; i++) {
        while(st.length != 0 && height[st[st.length - 1]] < height[i]) {
           let t = st.pop();
           if(st.length == 0) break;
           let h = Math.min(height[i], height[st[st.length - 1]]) - height[t];
           let l = i - st[st.length - 1] - 1;
           ans += (l * h);
        }
        st.push(i);
    }

    return ans;
};