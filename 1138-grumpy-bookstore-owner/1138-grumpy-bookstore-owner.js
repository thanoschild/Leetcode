/**
 * @param {number[]} customers
 * @param {number[]} grumpy
 * @param {number} minutes
 * @return {number}
 */
var maxSatisfied = function(customers, grumpy, minutes) {
    const n = customers.length;
    let happyCustomers = 0;
    for(let i = 0; i<n; i++) {
        if(grumpy[i] == 0) {
            happyCustomers += customers[i];
            customers[i] = 0;
        }
    }

    let maxSum = 0, sum = 0;
    for(let i = 0; i<n; i++) {
        sum += customers[i];
        if(i >= minutes) {
            sum -= customers[i-minutes];
        }
        maxSum = Math.max(maxSum, sum);
    }

    return maxSum + happyCustomers;
};