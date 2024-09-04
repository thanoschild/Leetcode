/**
 * @param {number[]} commands
 * @param {number[][]} obstacles
 * @return {number}
 */
var robotSim = function(commands, obstacles) {
    const st = new Set();
    for (const obs of obstacles) {
        st.add(`${obs[0]}-${obs[1]}`);
    }

    const dirs = [
        [0, 1],   
        [1, 0],   
        [0, -1],  
        [-1, 0]   
    ];
    let d = 0;
    let x = 0, y = 0;
    let ans = 0;

    for (let c of commands) {
        if (c === -1) {
            d = (d + 1) % 4;
        } else if (c === -2) {
            d = (d - 1 + 4) % 4;
        } else {
            while (c-- > 0 && !st.has(`${x + dirs[d][0]}-${y + dirs[d][1]}`)) {
                x += dirs[d][0];
                y += dirs[d][1];
            }
        }
        ans = Math.max(ans, x * x + y * y);
    }

    return ans;
};