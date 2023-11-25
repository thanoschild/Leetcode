class Solution {
    public int maxCoins(int[] piles) {
        int max = 0, n = piles.length;
        for(int coin : piles) {
            if(coin > max) max = coin;
        }
        
        int[] freq = new int[max+1];
        for(int coin : piles) {
            freq[coin]++;
        }
        
        int ans = 0, turn = 0, chance = n/3, idx = max;
        while(chance > 0) {
            if(freq[idx] > 0) {
                if(turn == 0) turn = 1;
                else{
                    chance--;
                    turn = 0;
                    ans += idx;
                }
                freq[idx]--;
            }
            else{
                idx--;
            }
        }
        
        return ans;
    }
}