/**
 * @param {number[]} nums
 * @return {number[]}
 */

let count = [];

function merge(arr, left, mid, right) {
    const n1 = mid - left + 1;
    const n2 = right - mid;

    const arr1 = arr.slice(left, mid + 1);
    const arr2 = arr.slice(mid + 1, right + 1);

    let p = 0;
    let q = 0;
    let r = left;

    while (p < n1 && q < n2) {
        if (arr1[p][0] <= arr2[q][0]) {
            count[arr1[p][1]] += q;
            arr[r] = arr1[p];
            r++;
            p++;
        } else {
            arr[r] = arr2[q];
            r++;
            q++;
        }
    }

    while (p < n1) {
        arr[r] = arr1[p];
        count[arr1[p][1]] += q;
        r++;
        p++;
    }

    while (q < n2) {
        arr[r] = arr2[q];
        r++;
        q++;
    }
}

function mergeSort(arr, left, right) {
    if (left < right) {
        const mid = Math.floor((right - left) / 2) + left;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

var countSmaller = function(nums) {
    const n = nums.length;
    count = Array(n).fill(0);

    const arr = nums.map((num, index) => [num, index]);

    mergeSort(arr, 0, n - 1);

    return count;
};