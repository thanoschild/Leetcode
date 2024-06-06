/**
 * @param {number[]} hand
 * @param {number} groupSize
 * @return {boolean}
 */
var isNStraightHand = function(hand, groupSize) {
    const n = hand.length;
    if (n % groupSize !== 0) return false;

    const countMap = new Map();
    for (const num of hand) {
        countMap.set(num, (countMap.get(num) || 0) + 1);
    }

    const keys = Array.from(countMap.keys()).sort((a, b) => a - b);
    for (const key of keys) {
        const count = countMap.get(key);
        if (count > 0) {
            for (let i = groupSize-1; i >= 0; i--) {
                const currentKey = key + i;
                const currentCount = countMap.get(currentKey) || 0;
                if (currentCount < count) {
                    return false;
                }
                countMap.set(currentKey, currentCount - count);
            }
        }
    }

    return true;
};