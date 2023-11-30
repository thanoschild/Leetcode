class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0) return 0;
        vector<int> p(31, 0);
        p[0] = 1;
        int count = 1;
        for(int i = 1; i<31; i++) {
            count *= 2;
            p[i] = p[i-1] + count;
        }
        
        int bits = 32 - __builtin_clz(n);
        long long ans = 0;
        bool add = true;
        
        for(int i = bits - 1; i>=0; i--) {
            if(n & (1 << i)) {
                if(add){
                    ans += p[i];
                    add = false;
                }
                else{
                    ans -= p[i];
                    add = true;
                }
            }
        }
        
        return ans;
    }
};