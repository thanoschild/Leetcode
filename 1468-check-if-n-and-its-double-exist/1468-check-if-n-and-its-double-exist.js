/**
 * @param {number[]} arr
 * @return {boolean}
 */
var checkIfExist = function(arr) {
    const st = new Set();
    for(const it of arr) {
        if(st.has(it*2) || st.has(it/2)) return true;
        st.add(it);
    }

    return false;
};