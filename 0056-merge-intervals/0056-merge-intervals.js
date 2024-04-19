/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    intervals.sort((a, b) => a[0] - b[0]);
    const ans = [];
    let currentInterval = intervals[0];

    for(let i = 1; i<intervals.length; i++) {
        if(currentInterval[1] >= intervals[i][0]) {
            currentInterval[0] = Math.min(currentInterval[0], intervals[i][0]);
            currentInterval[1] = Math.max(currentInterval[1], intervals[i][1]);
        }
        else {
            ans.push(currentInterval);
            currentInterval = intervals[i];
        }
    }
    ans.push(currentInterval);
    
    return ans;
};