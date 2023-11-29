class Solution {
public:
    int numberOfWays(string cor) {
        int seats = 0, n = cor.size(), mod = 1e9 + 7;
        for(int i = 0; i<n; i++) {
            if(cor[i] == 'S') seats++;
        }
        
        if(seats == 0 || seats % 2) return 0;
        
        long long ans = 1, count = 0, plant = 0;
        for(int i = 0; i<n; i++) {
            if(cor[i] == 'S') count++;
            if(count == 2) {
                i++, plant = 1;
                while(i<n && cor[i] == 'P') plant++, i++;
                if(i == n) break;
                ans = (ans * plant)%mod;
                count = 0, i--;
            }
        }
        
        return (int)ans;
    }
};