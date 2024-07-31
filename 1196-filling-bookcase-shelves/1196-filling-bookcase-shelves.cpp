class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        if(n == 0) return 0;

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i<=n; i++) {
            int currWidth = 0, currHeight = 0, k = 1;
            while(k <= i) {
                currHeight = max(currHeight, books[i-k][1]);
                currWidth += books[i-k][0];
                if(currWidth > shelfWidth) break;
                dp[i] = min(dp[i], dp[i - k] + currHeight);
                k++;
            }
        }

        return dp[n];
    }
};