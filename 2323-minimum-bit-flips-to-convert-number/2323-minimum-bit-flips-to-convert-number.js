/**
 * @param {number} start
 * @param {number} goal
 * @return {number}
 */
var minBitFlips = function(start, goal) {
    let _xor = start ^ goal, count = 0;
    for(let i = 0; i<32; i++) {
        if((_xor & (1 << i))> 0) count++;
    }

    return count;
};