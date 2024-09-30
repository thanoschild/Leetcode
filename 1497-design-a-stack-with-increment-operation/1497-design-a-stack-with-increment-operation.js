/**
 * @param {number} maxSize
 */
let stack = [];
let len;
var CustomStack = function(maxSize) {
    stack = [];
    len = maxSize;
};

/** 
 * @param {number} x
 * @return {void}
 */
CustomStack.prototype.push = function(x) {
    if(stack.length < len) stack.push(x);
};

/**
 * @return {number}
 */
CustomStack.prototype.pop = function() {
    if(stack.length > 0) return stack.pop();
    return -1;
};

/** 
 * @param {number} k 
 * @param {number} val
 * @return {void}
 */
CustomStack.prototype.increment = function(k, val) {
    for(let i = 0; i<k && i < stack.length; i++) stack[i] += val;
};

/** 
 * Your CustomStack object will be instantiated and called as such:
 * var obj = new CustomStack(maxSize)
 * obj.push(x)
 * var param_2 = obj.pop()
 * obj.increment(k,val)
 */