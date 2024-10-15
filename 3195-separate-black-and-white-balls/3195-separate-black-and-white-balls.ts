function minimumSteps(s: string): number {
    let ans: number = 0;
    let count : number = 0;

    for(const c of s) {
        if(c == '1') count++;
        else ans += count;
    }

    return ans;
};