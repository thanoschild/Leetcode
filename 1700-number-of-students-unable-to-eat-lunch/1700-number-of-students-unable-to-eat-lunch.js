/**
 * @param {number[]} students
 * @param {number[]} sandwiches
 * @return {number}
 */
var countStudents = function(students, sandwiches) {
    const freq = [0, 0];
    let n = students.length, i = 0;

    for(let val of students) {
        freq[val]++;
    }

    for(i = 0; i<n && freq[sandwiches[i]] > 0; i++) {
        freq[sandwiches[i]]--;
    }

    return n - i;
};