/**
 * @param {string} s
 * @return {string[][]}
 */

function check(s, i, j) {
    while (i < j) {
        if (s[i] !== s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

function solve(s, idx, curr, ans) {
    const n = s.length;
    if (idx === n) {
        ans.push([...curr]);
        return;
    }

    for (let i = idx; i < n; i++) {
        if (check(s, idx, i)) {
            curr.push(s.substring(idx, i + 1));
            solve(s, i + 1, curr, ans);
            curr.pop();
        }
    }
}

var partition = function(s) {
    const ans = [];
    if (s.length === 0) {
        return ans;
    }
    const curr = [];
    solve(s, 0, curr, ans);
    return ans;
};