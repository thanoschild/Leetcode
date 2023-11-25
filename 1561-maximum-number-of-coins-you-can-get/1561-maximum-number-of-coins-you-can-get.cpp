class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int max = 0, n = piles.size();
        for(int coin : piles) {
            if(coin > max) max = coin;
        }
        
        vector<int> freq(max+1, 0);
        for(int coin : piles) {
            freq[coin]++;
        }
        
        int ans = 0, turn = 0, chance = n/3, idx = max;
        while(chance > 0) {
            if(freq[idx] > 0) {
                if(turn == 0) turn = 1;
                else{
                    chance--;
                    ans += idx;
                    turn = 0;
                }
                freq[idx]--;
            }
            else{
                idx--;
            }
        }
        
        return ans;
    }
};