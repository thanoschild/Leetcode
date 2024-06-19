/**
 * @param {number[]} bloomDay
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var minDays = function(bloomDay, m, k) {
    let left = 0, right = 1000000009, ans = -1;

    while(left <= right) {
        let mid = Math.floor((right + left)/2);
        let buk = 0, con = 0;

        for(let n of bloomDay) {
            if(n <= mid) {
                con++;
                if(con >= k) {
                    buk++;
                    con = 0;
                }
            }
            else {
                con = 0;
            }
        }

        if(buk >= m) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return ans;
};