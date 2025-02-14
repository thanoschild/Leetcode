var prefix = new Array();
var ProductOfNumbers = function() {
    prefix.push(1);
};

/** 
 * @param {number} num
 * @return {void}
 */
ProductOfNumbers.prototype.add = function(num) {
    if(num > 0) prefix.push(prefix[prefix.length - 1] * num);
    else {
       prefix = new Array();
       prefix.push(1);
    }
};

/** 
 * @param {number} k
 * @return {number}
 */
ProductOfNumbers.prototype.getProduct = function(k) {
    const n = prefix.length;
    return k < n ? prefix[n - 1] / prefix[n-1-k] : 0;
};

/** 
 * Your ProductOfNumbers object will be instantiated and called as such:
 * var obj = new ProductOfNumbers()
 * obj.add(num)
 * var param_2 = obj.getProduct(k)
 */