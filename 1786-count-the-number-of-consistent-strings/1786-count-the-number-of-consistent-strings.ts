function countConsistentStrings(allowed: string, words: string[]): number {
    const st = new Set();
    for(let c of allowed) st.add(c);
    let count: number = 0;
    let flag: boolean = true;

    for(let s of words) {
        flag = true;
        for(let c of s) {
            if(!st.has(c)) {
                flag = false;
                break;
            }
        }

        if(flag) count++;
    }

    return count;
};