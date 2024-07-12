/**
 * @param {string} s
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var maximumGain = function(s, x, y) {
    let top, bot, topScore, botScore;

    if (x > y) {
        top = "ab";
        topScore = x;
        bot = "ba";
        botScore = y;
    } else {
        top = "ba";
        topScore = y;
        bot = "ab";
        botScore = x;
    }

    let stack = [];
    let ans = 0;
    for (let c of s) {
        if (c === top[1] && stack.length && stack[stack.length - 1] === top[0]) {
            ans += topScore;
            stack.pop();
        } else {
            stack.push(c);
        }
    }

    let stack1 = [];
    for (let c of stack) {
        if (c === bot[1] && stack1.length && stack1[stack1.length - 1] === bot[0]) {
            ans += botScore;
            stack1.pop();
        } else {
            stack1.push(c);
        }
    }

    return ans;
};