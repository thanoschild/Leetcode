class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : nums) {
            if(it < k) pq.push(it);
        }

        int ops = 0;
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            ops++;

            if(pq.empty()) break;
            int y = pq.top();
            pq.pop();

            long long val = 2L * x + y;
            if(val < k) pq.push((int)val);
        }

        return ops;
    }
};