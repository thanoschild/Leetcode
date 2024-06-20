/**
 * @param {number[]} position
 * @param {number} m
 * @return {number}
 */
var maxDistance = function(position, m) {
    position.sort((a, b) => a - b);
    let n = position.length;
    let left = 0, right = position[n-1], ans = 0;

    while(left <= right) {
        let mid = Math.floor((right + left)/2);
        let curr = position[0], count = 1;
        for(let i = 1; i<n; i++) {
            if(position[i] - curr >= mid) {
                count++;
                curr = position[i];
            }
        }

        if(count >= m) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return ans;
};