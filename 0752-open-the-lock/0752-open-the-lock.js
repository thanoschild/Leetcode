/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
function possibleWays(str) {
    let ways = [];
    for (let i = 0; i < 4; i++) {
        let curr = str;
        if (curr[i] === '9') curr = curr.substr(0, i) + '0' + curr.substr(i + 1);
        else curr = curr.substr(0, i) + (parseInt(curr[i]) + 1) % 10 + curr.substr(i + 1);
        ways.push(curr);

        curr = str;
        if (curr[i] === '0') curr = curr.substr(0, i) + '9' + curr.substr(i + 1);
        else curr = curr.substr(0, i) + (parseInt(curr[i]) - 1 + 10) % 10 + curr.substr(i + 1);
        ways.push(curr);
    }
    return ways;
}

var openLock = function(deadends, target) {
    if (target === "0000") return 0;
    let check = new Set(deadends);
    let visited = new Set();
    let pq = ["0000"];
    let ans = 0;

    while (pq.length > 0) {
        let n = pq.length;
        for (let i = 0; i < n; i++) {
            let curr = pq.shift();
            console.log(curr);

            if (curr === target) return ans;
            if (visited.has(curr) || check.has(curr)) continue;

            let ways = possibleWays(curr);
            pq.push(...ways);
            visited.add(curr);
        }
        ans++;
    }

    return -1;
};