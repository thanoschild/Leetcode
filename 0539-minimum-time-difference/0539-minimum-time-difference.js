/**
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function(timePoints) {
    let seen = Array(24 * 60).fill(false);
    let maxMin = -Infinity, minMin = Infinity;

    for (let s of timePoints) {
        let [h, m] = s.split(":").map(Number);
        let totalMinutes = h * 60 + m;

        if (seen[totalMinutes]) return 0;

        maxMin = Math.max(maxMin, totalMinutes);
        minMin = Math.min(minMin, totalMinutes);
        seen[totalMinutes] = true;
    }

    let diff = Infinity, prev = null;

    for (let i = minMin; i <= maxMin; i++) {
        if (seen[i]) {
            if (prev === null) {
                diff = Math.min(diff, Math.min(maxMin - minMin, 1440 - maxMin + minMin));
            } else {
                diff = Math.min(diff, i - prev);
            }
            prev = i;
        }
    }

    return diff;
};