class Solution(object):
    def maxCoins(self, piles):
        max_coin, n = max(piles), len(piles)
        freq = [0]*(max_coin + 1)
        
        for x in piles:
            freq[x] += 1
        
        ans, turn, chance, idx = 0, 0, n//3, max_coin
        while chance > 0:
            if freq[idx] > 0:
                if turn == 0: turn = 1
                else:
                    turn = 0
                    chance -= 1
                    ans += idx
                freq[idx] -= 1
            else:
                idx -= 1
                
        return ans
        