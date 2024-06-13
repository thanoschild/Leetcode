/**
 * @param {number[]} seats
 * @param {number[]} students
 * @return {number}
 */
var minMovesToSeat = function(seats, students) {
    seats.sort((a, b) => a - b);
    students.sort((a, b) => a - b);
    
    let ans = 0, n = seats.length;
    for(let i = 0; i<n; i++) {
        ans += Math.abs(seats[i] - students[i]);
    }

    return ans;
};