/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
function findCounts(arr, mid) {
    let j = 1, total = 0, num = 0, den = 0, n = arr.length;
    let frac = 0.0;

    for (let i = 0; i < n; i++) {
        while (j < n && arr[i] >= arr[j] * mid) j++;
        total += n - j;

        if (j < n && frac < arr[i] * 1.0 / arr[j]) {
            frac = arr[i] * 1.0 / arr[j];
            num = i, den = j;
        }
    }
    return [total, num, den];
}

var kthSmallestPrimeFraction = function(arr, k) {
    const n = arr.length;
    let left = 0, right = 1;
    let ans = [];

    while (left <= right) {
        const mid = (right - left) / 2 + left;
        const pos = findCounts(arr, mid);
        if (pos[0] === k) {
            ans = [arr[pos[1]], arr[pos[2]]];
            break;
        }

        if (pos[0] > k) right = mid;
        else left = mid;
    }

    return ans;
};