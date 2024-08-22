/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
    let mask = 0, temp = num;
    while(temp > 0) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    return num ^ mask;
};