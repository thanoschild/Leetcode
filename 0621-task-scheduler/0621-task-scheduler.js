/**
 * @param {character[]} tasks
 * @param {number} n
 * @return {number}
 */
var leastInterval = function(tasks, n) {
    let mp = new Map();
    let maxCount = 0;
    for (let i = 0; i < tasks.length; i++) {
        let c = tasks[i];
        mp.set(c, (mp.get(c) || 0) + 1);
        maxCount = Math.max(maxCount, mp.get(c));
    }

    let ans = (maxCount - 1) * (n + 1);
    for (let count of mp.values()) {
        if (count === maxCount) ans++;
    }

    return Math.max(ans, tasks.length);
};