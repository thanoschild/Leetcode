class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it : nums) pq.push(it);

        long long ans = 0;
        while(k-- && !pq.empty()) {
            int t = pq.top();
            pq.pop();
            ans += (long) t;
            int val = t/3;
            if(t%3 != 0) val++;
            pq.push(val);
        }

        return ans;
    }
};