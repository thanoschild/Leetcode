/**
 * @param {string[]} names
 * @param {number[]} heights
 * @return {string[]}
 */
var sortPeople = function(names, heights) {
    let map = new Map();

    for (let i = 0; i < names.length; i++) {
        map.set(heights[i], names[i]);
    }

    let sortedHeights = Array.from(map.keys()).sort((a, b) => b - a);
    let result = [];

    for (let height of sortedHeights) {
        result.push(map.get(height));
    }

    return result;
};