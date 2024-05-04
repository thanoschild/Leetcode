/**
 * @param {number[]} people
 * @param {number} limit
 * @return {number}
 */
var numRescueBoats = function(people, limit) {
    people.sort((a, b) => a - b);
    let i = 0, j = people.length - 1, ans = 0;

    while(i <= j) {
        let sum = people[i] + people[j];
        if(sum <= limit) {
            ans++; i++; j--;
        }
        else {
            ans++; j--;
        }
    }

    return ans;
};