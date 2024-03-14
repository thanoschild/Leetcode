/**
 * @param {number[]} tokens
 * @param {number} power
 * @return {number}
 */
var bagOfTokensScore = function(tokens, power) {
    let sortTokens = tokens.sort((a, b) => a - b);
    let points = 0, ans = 0, start = 0, end = tokens.length - 1;

    while(start <= end) {
        if(power >= sortTokens[start]) {
            power -= sortTokens[start];
            points++;
            ans = Math.max(ans, points);
            start++;
        }
        else if(points > 0) {
            points--;
            power += sortTokens[end];
            end--;
        }
        else break;
    }

    return ans;
};