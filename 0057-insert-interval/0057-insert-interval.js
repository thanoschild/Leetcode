/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    let ans = [];
    let n = intervals.length;
    let idx = 0;

    while(idx < n && intervals[idx][1] < newInterval[0]) {
        ans.push(intervals[idx]);
        idx++;
    } 

    while(idx < n && intervals[idx][0] <= newInterval[1]) {
        newInterval[0] = Math.min(newInterval[0], intervals[idx][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[idx][1]);
        idx++;

    }
    ans.push(newInterval);

    while(idx < n) {
        ans.push(intervals[idx]);
        idx++;
    }

    return ans;
};