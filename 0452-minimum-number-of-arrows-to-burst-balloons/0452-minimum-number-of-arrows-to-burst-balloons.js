/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    let n = points.length;
    if(n == 0) return 0;
    points.sort((a, b) => a[1] - b[1]);

    let arrows = 1, arrowPos = points[0][1];
    for(let i = 1; i<n; i++) {
        if(arrowPos >= points[i][0]) continue;
        arrows++;
        arrowPos = points[i][1];
    }

    return arrows;
};