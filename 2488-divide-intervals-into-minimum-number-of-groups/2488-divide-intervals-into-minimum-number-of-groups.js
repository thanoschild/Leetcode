/**
 * @param {number[][]} intervals
 * @return {number}
 */
var minGroups = function(intervals) {
    intervals.sort((a, b) => a[0] - b[0]);
    const pq = new MinPriorityQueue();

    for (let [start, end] of intervals) {
        if (!pq.isEmpty() && pq.front().element < start) {
            pq.dequeue(); 
        }
        pq.enqueue(end);
    }

    return pq.size();
};