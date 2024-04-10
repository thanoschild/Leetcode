class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> ans(n);
        queue<int> pq;

        for(int i = 0; i<n; i++) pq.push(i);

        for(int i = 0; i<n; i++) {
            ans[pq.front()] = deck[i];
            pq.pop();
            pq.push(pq.front());
            pq.pop();
        }

        return ans;
    }
};