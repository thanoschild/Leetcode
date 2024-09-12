/**
 * @param {string} allowed
 * @param {string[]} words
 * @return {number}
 */
var countConsistentStrings = function(allowed, words) {
    const st = new Set();
    for(let c of allowed) st.add(c);
    let count = 0;
    let flag = true;

    for(let s of words) {
        flag = true;
        for(let c of s) {
            if(!st.has(c)) {
                flag = false;
                break;
            }
        }

        if(flag) count++;
    }

    return count;
};