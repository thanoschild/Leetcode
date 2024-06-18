/**
 * @param {number[]} difficulty
 * @param {number[]} profit
 * @param {number[]} worker
 * @return {number}
 */
var maxProfitAssignment = function(difficulty, profit, worker) {
    let jobs = [];
    for (let i = 0; i < profit.length; i++) {
        jobs.push([difficulty[i], profit[i]]);
    }
    
    jobs.sort((a, b) => {
        if (a[0] === b[0]) {
            return b[1] - a[1]; 
        }
        return a[0] - b[0]; 
    });
    
    worker.sort((a, b) => a - b);
    
    let ans = 0, idx = 0, curr = 0;
    for (let i = 0; i < worker.length; i++) {
        while (idx < jobs.length && jobs[idx][0] <= worker[i]) {
            curr = Math.max(curr, jobs[idx][1]);
            idx++;
        }
        ans += curr;
    }
    
    return ans;
};