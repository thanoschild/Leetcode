/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function(s) {
    let leftmin = 0, leftmax = 0;
    for(let c of [...s]) {
        if(c === '(') {
            leftmax++;
            leftmin++;
        }
        else if(c === ')') {
            leftmin--;
            leftmax--;
        }
        else {
            leftmax++;
            leftmin--;
        }

        if(leftmax < 0) return false;
        if(leftmin < 0) leftmin = 0;
    }

    return leftmin == 0;
};