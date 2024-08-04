class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i<n; i++) {
            pq.push({nums[i], i+1});
        }

        int ans = 0, mod = 1e9 + 7;
        for(int i = 1; i<=right; i++) {
            auto t = pq.top();
            pq.pop();
            if(i >= left) ans = (ans + t.first) % mod;
            if(t.second < n) {
                t.first += nums[t.second++];
                pq.push(t);
            }
        }

        return ans;
    }
};