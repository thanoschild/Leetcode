long long minimumSteps(char* s) {
    long long ans = 0, count = 0;
    int len = strlen(s);
    for(int i = 0; i<len; i++) {
        if(s[i] == '1') count++;
        else ans += count;
    }

    return ans;
}