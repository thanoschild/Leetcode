class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> pq;
        for(int i = 1; i<=n; i++) pq.push(i);

        while(pq.size() > 1) {
            for(int i = 0; i<k-1; i++) {
                int t = pq.front();
                pq.pop();
                pq.push(t);
            }
            pq.pop();
        }

        return pq.front();
    }
};