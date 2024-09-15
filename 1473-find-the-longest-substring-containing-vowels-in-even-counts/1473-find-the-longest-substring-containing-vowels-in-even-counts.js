/**
 * @param {string} s
 * @return {number}
 */
var findTheLongestSubstring = function(s) {
    const mp = new Map();
    mp.set(0, -1);
    const v = "aeiou";
    let mask = 0, ans = 0;

    for (let i = 0; i < s.length; i++) {
        for (let j = 0; j < 5; j++) {
            if (s[i] === v[j]) {
                mask ^= (1 << j);
                break;
            }
        }

        if (!mp.has(mask)) {
            mp.set(mask, i);
        }

        ans = Math.max(ans, i - mp.get(mask));
    }

    return ans;
};