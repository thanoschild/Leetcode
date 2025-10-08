/**
 * @param {number[]} spells
 * @param {number[]} potions
 * @param {number} success
 * @return {number[]}
 */

function findIdx(spell, potions, success) {
    let ans = -1, start = 0, end = potions.length - 1;
    while(start <= end) {
        const mid = Math.floor((end - start)/2 + start);
        const currVal = potions[mid]* spell;
        if(currVal >= success) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

var successfulPairs = function(spells, potions, success) {
    potions.sort((a, b) => a - b);
    const n = spells.length;
    const m = potions.length;
    const arr = new Array(n);

    for(let i = 0; i<n; i++) {
        const pos = findIdx(spells[i], potions, success);
        if(pos == -1) arr[i] = 0;
        else {
            arr[i] = m - pos;
        }
    }

    return arr;
};