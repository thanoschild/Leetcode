/**
 * @param {string} s
 * @return {string}
 */
var minRemoveToMakeValid = function(s) {
    const stack = [];
    const chars = [...s];

    for(let i = 0; i<chars.length; i++) {
        if(chars[i] === '(') stack.push(i);
        else if(chars[i] === ')') {
            if(stack.length > 0) stack.pop();
            else chars[i] = '*'
        }
    }

    while(stack.length > 0) chars[stack.pop()] = '*';

    let ans = "";
    for(let i = 0; i<chars.length; i++) {
       if(chars[i] !== '*') ans += chars[i];
    }

    return ans;
};