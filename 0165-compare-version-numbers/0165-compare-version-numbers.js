/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(ver1, ver2) {
    let n1 = ver1.length, n2 = ver2.length;
    let i = 0, j = 0;

    while(i < n1 || j < n2) {
        let num1 = 0, num2 = 0;
        while(i < n1 && ver1[i] != '.') {
            num1 = num1*10 + (ver1[i].charCodeAt(0)- '0'.charCodeAt(0));
            i++;
        }
        while(j < n2 && ver2[j] != '.') {
            num2 = num2*10 + (ver2[j].charCodeAt(0)- '0'.charCodeAt(0));
            j++;
        }

        if(num1 > num2) return 1;
        else if(num2 > num1) return -1;
        i++; j++;
    }

    return 0;
};