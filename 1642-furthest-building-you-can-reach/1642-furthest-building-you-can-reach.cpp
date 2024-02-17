class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(), i = 0;
        priority_queue<int> pq;
        for(i = 0; i<n-1; i++) {
            int diff = heights[i+1] - heights[i];
            if(diff < 0) continue;
            else if(diff <= bricks) {
                bricks -= diff;
                pq.push(diff);
            }
            else if(ladders > 0) {
                if(!pq.empty() && pq.top() > diff) {
                    bricks += pq.top();
                    pq.pop();
                    bricks -= diff;
                    pq.push(diff);
                }
                ladders--;
            }
            else break;
        }

        return i;
    }
};