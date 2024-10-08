/**
 * @param {string} s
 * @return {number}
 */
var minSwaps = function(s) {
    const stack = [];
    let count = 0;

    for(const c of s) {
        if(c == '[') stack.push(c);
        else {
            if(stack.length > 0) stack.pop();
            else count++;
        }
    }

    return Math.floor((count + 1) / 2);
};