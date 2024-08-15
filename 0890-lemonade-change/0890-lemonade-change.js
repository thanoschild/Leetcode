/**
 * @param {number[]} bills
 * @return {boolean}
 */
var lemonadeChange = function(bills) {
    let fives = 0, tens = 0;
    for(let bill of bills) {
        if(bill == 5) fives++;
        else if(bill == 10) {
            tens++;
            fives--;
        }
        else if(tens > 0) {
            tens--;
            fives--;
        }
        else fives -= 3;

        if(fives < 0) return false;
    }

    return true;
};