/**
 * @param {string} s
 * @return {number}
 */
var maximumLength = function(s) {
    const mp = new Map();
    const n = s.length;

    for(let i = 0; i<n; i++) {
        let str = s[i];
        mp.set(str, (mp.get(str) || 0) + 1);

        for(let j = i; j<n-1; j++) {
            if(s[j] == s[j+1]) {
                str += s[j];
                mp.set(str, (mp.get(str) || 0) + 1);
            } else break;
        } 
    }

    let ans = 0;
    for(const [key, value] of mp.entries()) {
        if(value >= 3) {
            ans = Math.max(ans, key.length);
        }
    };

    return ans == 0 ? -1 : ans;
};