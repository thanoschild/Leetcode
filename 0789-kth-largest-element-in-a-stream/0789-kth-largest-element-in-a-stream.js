/**
 * @param {number} k
 * @param {number[]} nums
 */
var KthLargest = function(k, nums) {
    this.limit = k;
    this.pq = nums.sort((a, b) => a - b);
    while (this.pq.length > this.limit) {
        this.pq.shift(); 
    }
};

/** 
 * @param {number} val
 * @return {number}
 */
KthLargest.prototype.add = function(val) {
    let i = this.pq.findIndex(x => x > val);
    if (i === -1) {
        this.pq.push(val); 
    } else {
        this.pq.splice(i, 0, val); 
    }
    
    if (this.pq.length > this.limit) {
        this.pq.shift(); 
    }
    
    return this.pq[0];
};

/** 
 * Your KthLargest object will be instantiated and called as such:
 * var obj = new KthLargest(k, nums)
 * var param_1 = obj.add(val)
 */